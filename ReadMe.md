# VideoPlayer

Qt 4.8.5ʵ����Ƶ���ſͻ��ˡ�

## ʹ��˵��

- ��Դ��ȡ·��Ϊ"../resource/xxx.xxx"��
- Ϊ������ԣ��û������벻��Ҫ��֤���ɵ�¼��

## ����ṹ

### LoginDialog

- ��½����
- ��������������޷��������⣺��½����Ϊģ̬���ڣ���main��ʹ��exec()��������������̴��ڱ�������Ϊģ̬���ڣ��źŲſɴ��롣

### QtClickableLabel

- QLabel��������࣬��������¼�������¼�������ʵ�ֶ�Label�Ĳ����������¼���δʵ�֡�
- ���������к����ؼ���ʹ�ø��࣬����ʵ���������ת����Ƶ���Ž��档
- Ŀǰ�����ת�Ƶ��ÿռ䣬�����޷�Ӧ��

### mainWindow

- �����ڽ���
- �ɵ���Ŀؼ����������Tab���л����س���ѡ��
- �����������ź���sendData(QString)��sendPath(QString)���ֱ���������Ƶ�б��ݵ�ǰ��ѡ�����Ŀ������Ƶ���Ŵ��ڴ�����Ƶ·����

### VideoListDialog

- ��Ƶ�б����
- �������ź���sendPath(QString)����������Ƶ���Ŵ��ڴ�����Ƶ·����
- ���������ڴ��ݵĲ������Ϸ�Label��ʾ��ǰ��Ŀ����

### VideoPlayerDialog

- ʹ��Phonon/VideoPlayer������Ƶ�ļ���
- ��ȫ�����ţ�Esc���˳�����Ϊʹ����Dialog���ڣ�����Ϊ�˷�ֹ�˳�ȫ��ͬʱ�Ƴ����Ž��棬������Dialog��Esc���˳����ܡ�
- ʹ��Phonon��Ҫ��pro�ļ��м���
```
Qt += phonon
```

### MyInputPanel��MyInputPanelContext

- Qt�Դ����뷨�ؼ���ֱ�ӽ�Դ�ļ�������Ŀ����main()��ʹ��
```cpp
MyInputPanelContext *ic = new MyInputPanelContext;
app.setInputContext(ic);
```
���ص������С�
- ��myinputpanelcontext.cpp�й��캯���ڼ���
```cpp
inputPanel->setWindowModality(Qt::WindowModal);
```
�������뷨����Ϊģ̬���ڡ�
