# Git 基础命令学习记录

## 一、Git 简介

Git 是一个分布式版本控制系统，用于跟踪文件变化，尤其适用于团队协作开发。通过 Git，可以方便地进行代码版本管理、分支开发以及多人协作。

---

## 二、仓库初始化与获取

### 1. `git init`

**作用：**
在当前目录初始化一个 Git 仓库。

**使用场景：**
你想把一个已有项目纳入 Git 管理。

**示例：**

```bash
git init
```

**说明：**

* 会在当前目录生成一个 `.git` 文件夹
* 表示该目录已成为 Git 仓库

**注意：**

必须要在一个**空项目**中使用该命令！

---

### 2. `git clone`

**作用：**
从远程仓库复制一个项目到本地。

**示例：**

```bash
git clone https://github.com/your-name/your-repo-name.git
```

**说明：**

* 会自动下载代码
* 同时自动配置远程仓库（默认名称为 `origin`）

---

## 三、文件提交流程

Git 的基本工作流程：

```text
工作区 → 暂存区 → 本地仓库 → 远程仓库
```

---

### 3. `git add`

**作用：**
将文件添加到暂存区。

**示例：**

```bash
git add file.txt        # 添加单个文件
git add .               # 添加所有修改
```

---

### 4. `git commit`

**作用：**
将暂存区内容提交到本地仓库。

**示例：**

```bash
git commit -m "提交说明"
```

**说明：**

* `-m` 后面必须写清楚本次修改内容
* 每次 commit 都是一个版本记录

---

### 5. `git status`

**作用：**
查看当前仓库状态。

**示例：**

```bash
git status
```

**可以看到：**

* 哪些文件被修改
* 哪些文件已暂存
* 当前所在分支

---

## 四、历史记录与版本回退

### 6. `git reflog`

**作用：**
查看所有操作记录（包括回退操作）。

**示例：**

```bash
git reflog
```

**特点：**

* 比 `git log` 更全面
* 可以找回“误删”的提交

---

### 7. `git reset`

**作用：**
回退版本。

**常见用法：**

```bash
git reset --hard HEAD~1     # 回退到上一个版本
git reset --hard <commit_id>  # 回退到指定版本
```

**参数说明：**

* `--soft`：只回退 commit
* `--mixed`（默认）：回退 commit + 暂存区
* `--hard`：全部回退（危险！危险！危险！所有未保存的更改都会被删除，无法恢复！）

---

## 五、远程仓库操作

### 8. `git remote add origin`

**作用：**
添加远程仓库地址。

**示例：**

```bash
git remote add origin https://github.com/your-name/your-repo-name.git
```

---

### 9. `git push`

**作用：**
将本地代码推送到远程仓库。

**示例：**

```bash
git push origin main
```

---

### 10. `git pull`

**作用：**
从远程仓库拉取代码并合并。

**示例：**

```bash
git pull origin main
```

---

## 六、分支管理

### 11. `git branch`

**作用：**
查看或创建分支。

**示例：**

```bash
git branch             # 查看本地分支
git branch dev         # 创建 dev 分支
```

---

### 12. `git branch -a / -r`

**作用：**

* 查看所有分支（包括远程）

```bash
git branch -a   # 所有分支
git branch -r   # 远程分支
```

---

### 13. `git checkout -b`

**作用：**
创建并切换到新分支。

**示例：**

```bash
git checkout -b dev
```

**等价于：**

```bash
git branch dev
git checkout dev
```

---

## 七、常见完整工作流程

### 场景：修改代码并提交到 GitHub

```bash
# 1. 拉取最新代码
git pull origin main

# 2. 修改文件

# 3. 查看状态
git status

# 4. 添加文件
git add .

# 5. 提交
git commit -m "完成某个功能"

# 6. 推送到远程
git push origin main
```

---

## 八、常见问题与建议

### 1. 提交信息要清晰

* ❌ “修改了一些东西”
* ✅ “修复登录接口 bug”

---

### 2. 避免使用 `--hard` 重置（危险）

可能导致数据丢失。

---

### 3. 多用分支开发

* main：稳定版本
* dev：开发版本
* feature：功能分支

---

## 九、总结

| 命令            | 作用           |
| --------------- | -------------- |
| git init        | 初始化仓库     |
| git clone       | 克隆仓库       |
| git add         | 添加到暂存区   |
| git commit      | 提交到本地     |
| git status      | 查看状态       |
| git reflog      | 查看操作记录   |
| git reset       | 回退版本       |
| git remote add  | 添加远程仓库   |
| git push        | 推送代码       |
| git pull        | 拉取代码       |
| git branch      | 分支管理       |
| git checkout -b | 创建并切换分支 |
