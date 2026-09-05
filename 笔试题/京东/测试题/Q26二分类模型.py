import torch
import torch.nn as nn
from torch.utils.data import TensorDataset, DataLoader


# =========================
# 1. 定义模型
# =========================

class MLP(nn.Module):
    def __init__(self, input_dim, hidden_dim=64):
        super().__init__()

        self.net = nn.Sequential(
            nn.Linear(input_dim, hidden_dim),
            nn.ReLU(),

            # 最后一层只输出 1 个数。
            # 注意：这里不要加 Sigmoid，
            # 因为训练时使用 BCEWithLogitsLoss。
            nn.Linear(hidden_dim, 1)
        )

    def forward(self, x):
        return self.net(x)


# =========================
# 2. 验证函数
# =========================

def evaluate(model, val_loader, device):
    # 切换到验证模式。
    # Dropout / BatchNorm 等层会采用推理行为。
    model.eval()

    all_preds = []
    all_labels = []

    # 验证时不需要求梯度，
    # 可以减少计算量和显存占用。
    with torch.no_grad():

        for xb, yb in val_loader:
            xb = xb.to(device)
            yb = yb.to(device)

            # Linear(..., 1) 输出形状为 [batch_size, 1]。
            # squeeze(1) 后变成 [batch_size]，
            # 与标签形状保持一致。
            logits = model(xb).squeeze(1)

            # 模型输出的是 logit，
            # 推理阶段手动转成正类概率。
            probs = torch.sigmoid(logits)

            # >= 0.5 判为正类 1。
            preds = (probs >= 0.5).int()

            all_preds.append(preds.cpu())
            all_labels.append(yb.int().cpu())

    # F1 应该在整个验证集上统一计算，
    # 而不是每个 batch 算 F1 后再平均。
    all_preds = torch.cat(all_preds)
    all_labels = torch.cat(all_labels)

    # TP：真实为 1，预测也为 1
    tp = (
        (all_preds == 1) &
        (all_labels == 1)
    ).sum().item()

    # FP：真实为 0，却预测成 1
    fp = (
        (all_preds == 1) &
        (all_labels == 0)
    ).sum().item()

    # FN：真实为 1，却预测成 0
    fn = (
        (all_preds == 0) &
        (all_labels == 1)
    ).sum().item()

    # F1 = 2TP / (2TP + FP + FN)
    denominator = 2 * tp + fp + fn

    if denominator == 0:
        return 0.0

    return 2 * tp / denominator


# =========================
# 3. 完整训练函数
# =========================

def train_model(
    X_train,
    y_train,
    X_val,
    y_val,
    hidden_dim=64,
    batch_size=32,
    epochs=10,
    lr=1e-3
):
    # 有 CUDA 就用 GPU，否则使用 CPU。
    device = torch.device(
        "cuda" if torch.cuda.is_available() else "cpu"
    )

    # BCEWithLogitsLoss 需要浮点标签。
    X_train = X_train.float()
    y_train = y_train.float()

    X_val = X_val.float()
    y_val = y_val.float()

    # TensorDataset 把 X[i] 和 y[i] 组成一条样本。
    train_dataset = TensorDataset(X_train, y_train)
    val_dataset = TensorDataset(X_val, y_val)

    # 训练集通常打乱，
    # 避免每个 epoch 都按照完全相同的样本顺序训练。
    train_loader = DataLoader(
        train_dataset,
        batch_size=batch_size,
        shuffle=True
    )

    # 验证集不需要 shuffle。
    val_loader = DataLoader(
        val_dataset,
        batch_size=batch_size,
        shuffle=False
    )

    # 输入特征维数。
    input_dim = X_train.shape[1]

    model = MLP(
        input_dim=input_dim,
        hidden_dim=hidden_dim
    ).to(device)

    # BCEWithLogitsLoss =
    # Sigmoid + Binary Cross Entropy。
    #
    # 所以训练阶段不要自己 sigmoid。
    criterion = nn.BCEWithLogitsLoss()

    # AdamW 根据梯度更新模型参数。
    optimizer = torch.optim.AdamW(
        model.parameters(),
        lr=lr
    )

    # =========================
    # 4. Epoch 训练循环
    # =========================

    for epoch in range(epochs):

        # 切换到训练模式。
        model.train()

        total_loss = 0.0
        total_samples = 0

        for xb, yb in train_loader:
            xb = xb.to(device)
            yb = yb.to(device)

            # PyTorch 默认会累加梯度，
            # 所以每个 batch 开始前先清空旧梯度。
            optimizer.zero_grad()

            # 前向传播。
            #
            # 原始输出：
            # [batch_size, 1]
            #
            # squeeze 后：
            # [batch_size]
            logits = model(xb).squeeze(1)

            # 直接把 logits 送入 BCEWithLogitsLoss。
            # 这里不要手动调用 sigmoid。
            loss = criterion(logits, yb)

            # 根据 loss 反向传播，
            # 计算每个参数的梯度。
            loss.backward()

            # AdamW 读取参数的 .grad，
            # 并真正更新模型参数。
            optimizer.step()

            # 记录当前 epoch 的平均 loss。
            batch_size_now = xb.size(0)

            total_loss += loss.item() * batch_size_now
            total_samples += batch_size_now

        train_loss = total_loss / total_samples

        # 每个 epoch 结束后验证一次。
        val_f1 = evaluate(
            model,
            val_loader,
            device
        )

        print(
            f"Epoch {epoch + 1:02d} | "
            f"Loss: {train_loss:.4f} | "
            f"Val F1: {val_f1:.4f}"
        )

    return model


# model = train_model(
#     X_train,
#     y_train,
#     X_val,
#     y_val,
#     hidden_dim=64,
#     batch_size=32,
#     epochs=10,
#     lr=1e-3
# )