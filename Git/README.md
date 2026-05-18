# 初次创建Github项目
## 初始化本地仓（输出.git文件夹）
git init
## 将项目文件夹中的所有文件添加到本地仓库中。（注意add后面有一个点，代表当前目录的意思。）
git add . 
## 配置用户基本信息
git config --global user.name <此处输入用户名>
git config --global user.email <此处输入邮箱地址>
## 添加到工作区
git commit -m "本次提交注释"
## 输入以下指令将本地仓库关联到第一步创建的仓库中
git remote add origin <这里填入github中创建的项目地址>
## 输入以下指令将远程仓库中的README.txt与本地仓库的内容合并（如果没有创建README文件，此步略去）
git pull --rebase origin main
## 将本地项目push到创建的远程仓库中（这时会有验证的操作，确认即可，然后等待上传完成，刷新远程仓库网页，就可以看到上传的代码了。）
git push -u origin main

# Github常用命令
## 配置用户基本信息
git config --global user.name <此处输入用户名>
git config --global user.email <此处输入邮箱地址>
## 初始化一个新仓库
git init
## 从远程服务器克隆一个仓库
git clone <此处填入远程仓库的url>
## 显示当前地工作目录下的提交文件状态
git status
## 将指定文件stage标记为将要被提交的文件(.表示全部文件)
git add <此处填入文件路径>
## 显示提交历史
git log
## 更改本地分支名（本地 master 重命名为 main）
git branch -m master main
## 创建一个提交并提供提交信息
git commit -m "提交信息"
## 向远程仓库推送（push）
git push
## 从远程仓库拉取（pull）
git pull
## 将文件从暂存区（staging area）移除，但保留工作区文件内容不变。(简单说就是“取消暂存”，相当于撤销了 git add <文件> 的操作。)
git reset <文件路径>
## 仅撤销 commit，保留所有修改（最常用）
git reset --soft HEAD~1




