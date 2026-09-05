"""
Package Dependency Management
输入：
3
0 1.0.0 1>=2.0.0
1 4.0.0
2 3.0.0 1<=3.0.0
输出：
-1

输入：
3
0 1.0.0 1
1 2.0.0 2
2 3.0.0 0
输出：
-2

输入：
3
0 1.0.0 1>=2.0.0
1 4.0.0
2 3.0.0 1>=3.0.0
输出：
1 0 2

解题思路：
字符串解析+版本比较+DAG拓扑排序
1. 读取pack版本，检查他的依赖信息，冲突就直接返回-1
2. 依赖关系构建DAG，拓扑排序，如果有环就返回-2
3. 输出拓扑排序结果
"""

from collections import deque
import re

def version_tuple(version):
    parts = tuple(map(int, version.split(".")))
    while len(parts) > 1 and parts[-1] == 0:
        parts = parts[:-1]
    return parts + (0,) * (3 - len(parts))


def parse_dependency(token):
    match = re.fullmatch(r"(\d+)(?:(>=|<=|==|>|<)(\d+(?:\.\d+)*))?", token)
    if not match:
        return None

    package_id = int(match.group(1))
    operator = match.group(2)
    required_version = (
        version_tuple(match.group(3)) if match.group(3) is not None else None
    )
    return package_id, operator, required_version


def func():
    n = int(input())
    versions = {}
    requirements = {}
    graph = [[] for _ in range(n)]
    indegree = [0] * n

    for _ in range(n):
        package_id, version, *dependencies = input().split()
        package_id = int(package_id)
        if not 0 <= package_id < n or package_id in versions:
            print(-1)
            return
        versions[package_id] = version_tuple(version)

        for dependency in dependencies:
            parsed = parse_dependency(dependency)
            if parsed is None:
                print(-1)
                return

            dependency_id, operator, required_version = parsed
            if not 0 <= dependency_id < n:
                print(-1)
                return
            if operator is not None:
                requirements.setdefault(dependency_id, []).append(
                    (operator, required_version)
                )

            graph[dependency_id].append(package_id)
            indegree[package_id] += 1

    for package_id, package_requirements in requirements.items():
        if package_id not in versions:
            print(-1)
            return

        for operator, required_version in package_requirements:
            actual_version = versions[package_id]
            if not {
                ">=": actual_version >= required_version,
                "<=": actual_version <= required_version,
                "==": actual_version == required_version,
                ">": actual_version > required_version,
                "<": actual_version < required_version,
            }[operator]:
                print(-1)
                return

    queue = deque(package_id for package_id in range(n) if indegree[package_id] == 0)
    order = []
    while queue:
        package_id = queue.popleft()
        order.append(package_id)
        for dependent in graph[package_id]:
            indegree[dependent] -= 1
            if indegree[dependent] == 0:
                queue.append(dependent)

    if len(order) != n:
        print(-2)
    else:
        print(*order)


if __name__ == "__main__":
    func()
