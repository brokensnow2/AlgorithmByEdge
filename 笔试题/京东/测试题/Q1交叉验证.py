import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import f1_score
from sklearn.model_selection import StratifiedKFold

def solution(train, test, C_grid, kfold):
    """
    通过分层K折交叉验证选择最优的正则化参数C和分类阈值。
    
    Args:
        train: 训练集数据，最后一列为标签
        test: 测试集数据（无标签）
        C_grid: 正则化参数C的候选值列表
        kfold: 交叉验证的折数
    
    Returns:
        dict: 包含best_C、best_threshold和pred的结果字典
    """
    # 数据类型转换
    train = np.asarray(train, dtype=float)
    test = np.asarray(test, dtype=float)
    
    # 分离特征和标签
    X, y = train[:, :-1], train[:, -1].astype(int)
    
    # 特征标准化（Z-score）
    mean = X.mean(axis=0)
    std = X.std(axis=0, ddof=0)
    std[std == 0] = 1.0  # 避免常数特征导致的除零
    X = (X - mean) / std
    test = (test - mean) / std

    # 初始化分层K折分割器
    skf = StratifiedKFold(kfold, shuffle=True, random_state=42)
    # 阈值候选值：0.1~0.9
    thresholds = np.arange(1, 10) / 10.0
    best = None

    # 遍历每个C值
    for C in map(float, C_grid):
        # 为每个阈值存储K折的F1分数
        scores = [[] for _ in thresholds]
        
        # K折交叉验证
        for tr, va in skf.split(X, y):
            # 创建并训练逻辑回归模型
            model = LogisticRegression(
                C=C, penalty='l2', solver='lbfgs',
                max_iter=1000, random_state=42)
            model.fit(X[tr], y[tr])
            
            # 获取验证集的正类概率
            prob = model.predict_proba(X[va])[:, 1]
            
            # 尝试每个阈值
            for i, t in enumerate(thresholds):
                # 根据阈值转换为预测标签
                pred = (prob >= t).astype(int)
                # 计算F1分数
                scores[i].append(f1_score(y[va], pred, zero_division=0))

        # 计算每个阈值的平均F1分数
        for t, vals in zip(thresholds, scores):
            mean_f1 = float(np.mean(vals))
            # 比较标准：F1大优先 > C小优先 > 阈值小优先
            cand = (-mean_f1, C, float(t))
            if best is None or cand < best:
                best = cand

    # 提取最优参数
    _, best_C, best_t = best
    
    # 用最优参数在全部训练数据上重新训练
    model = LogisticRegression(
        C=best_C, penalty='l2',
        solver='lbfgs', max_iter=1000,
        random_state=42)
    model.fit(X, y)
    
    # 预测测试集
    prob = model.predict_proba(test)[:, 1]
    pred = (prob >= best_t).astype(int).tolist()
    
    return {'best_C': best_C, 'best_threshold': best_t, 'pred': pred}

if __name__ == '__main__':
    train = [
        [-2.0, -1.0, 0], [-1.5, -0.5, 0], [-1.0, -1.5, 0],
        [-0.5, -1.0, 0], [-1.0, -0.5, 0], [0.5, 1.0, 1],
        [1.0, 0.5, 1], [1.0, 1.5, 1], [1.5, 1.0, 1], [2.0, 1.5, 1],
    ]
    test = [[-1.2, -0.8], [0.8, 1.1], [1.5, 0.7]]
    print(solution(train, test, C_grid=[0.01, 0.1, 1.0, 10.0], kfold=5))