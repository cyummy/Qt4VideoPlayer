# VideoPlayer

Qt 4.8.5实现视频播放客户端。

## 使用说明

- 资源读取路径为"../resource/xxx.xxx"。
- 为方便测试，用户名密码不需要验证即可登录。

## 代码结构

### LoginDialog

- 登陆界面
- 解决外挂虚拟键盘无法输入问题：登陆界面为模态窗口（在main中使用exec()启动），虚拟键盘窗口必须设置为模态窗口，信号才可传入。

### QtClickableLabel

- QLabel类的衍生类，加入鼠标事件与键盘事件，用于实现对Label的操作，键盘事件现未实现。
- 程序中所有海报控件都使用该类，可以实现鼠标点击跳转到视频播放界面。
- 目前焦点可转移到该空间，按键无反应。

### mainWindow

- 主窗口界面
- 可点击的控件焦点可以用Tab键切换，回车键选择。
- 定义了两个信号量sendData(QString)，sendPath(QString)，分别用于向视频列表传递当前所选择的栏目，向视频播放窗口传递视频路径。

### VideoListDialog

- 视频列表界面
- 定义了信号量sendPath(QString)，用于向视频播放窗口传递视频路径。
- 根据主窗口传递的参数在上方Label显示当前栏目名。

### VideoPlayerDialog

- 使用Phonon/VideoPlayer播放视频文件。
- 可全屏播放，Esc键退出。因为使用了Dialog窗口，所以为了防止退出全屏同时推出播放界面，禁用了Dialog的Esc键退出功能。
- 使用Phonon库要在pro文件中加入
```
Qt += phonon
```

### MyInputPanel，MyInputPanelContext

- Qt自带输入法控件，直接将源文件导入项目，在main()中使用
```cpp
MyInputPanelContext *ic = new MyInputPanelContext;
app.setInputContext(ic);
```
挂载到程序中。
- 在myinputpanelcontext.cpp中构造函数内加入
```cpp
inputPanel->setWindowModality(Qt::WindowModal);
```
设置输入法窗口为模态窗口。
