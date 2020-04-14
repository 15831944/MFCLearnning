#include "PipeList.h"


void PipeList::recover(){
	int count=pipe.GetCount();
	for(int i=0;i<count;i++){
		pipe.RemoveHead();
	}
}
void PipeList::add(){
	Pipe temp;
	pipe.AddTail(temp);
}
void PipeList::logic(int &goals,Bird &bird,int &game_state){//�߼�����
	int count=pipe.GetCount();
	for(int i=0;i<count;i++){
		Pipe temp=pipe.GetHead();
		pipe.RemoveHead();
		temp.logic();
		//�ܵ��ƶ���64λ��
		if(temp.pos_x==64){
			goals+=1;
			mciSendString(_T("close mymusic"), NULL, 0, NULL);//�ȹ��ٿ���ע��˳�򣡣���
			mciSendString(mcicmd, NULL,0, NULL);
			mciSendString(_T("play mymusic"),NULL,0, NULL);	
		}
		if(temp.pos_x>=-70)pipe.AddTail(temp);

		//��ײ���
		if(23+bird.y+48-$d>400){//�����
			bird.y=400-230-48+$d;//�����ڵ���
			bird.stop();
			game_state=2;
		}else if(!(65+48-$d < temp.pos_x || temp.pos_x+52<65+$d)){//������
			if(!(230+bird.y+$d > temp.pos_y+320 && temp.pos_y+420 > 230+bird.y+48-$d)){
				game_state=2;//��ʾ��ײ,��Ϸ����;
				PlaySound(MAKEINTRESOURCE(IDR_WAVE_HIT),AfxGetResourceHandle(),SND_RESOURCE|SND_ASYNC);
			}
		}
	}
	if((pipe.GetTail()).pos_x<=140){
		Pipe temp;
		pipe.AddTail(temp);
	}
}
void PipeList::draw(Pic &All,CDC* To,CDC* From){//���ƺ���
	int count=pipe.GetCount();
	for(int i=0;i<count;i++){
		Pipe temp=pipe.GetHead();
		pipe.RemoveHead();
		pipe.AddTail(temp);
		All.pipe_down.TBlt(temp.pos_x,temp.pos_y,To,From);//������
		All.pipe_up.TBlt(temp.pos_x,temp.pos_y+420,To,From);//������
	}
}
//---------------------------------------------------------------
bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{
	// �����ļ�
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// ������Դ�ļ��С�������Դ���ڴ桢�õ���Դ��С
	HRSRC	hRes	= ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem	= ::LoadResource(NULL, hRes);
	DWORD	dwSize	= ::SizeofResource(NULL, hRes);
	
	// д���ļ�
	DWORD dwWrite = 0;  	// ����д���ֽ�
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}
//--------------------------------------------------------------
PipeList::PipeList(){
	// ������ʱ�ļ����ļ���
	TCHAR tmpwav[_MAX_PATH];
	::GetTempPath(_MAX_PATH,tmpwav);
	_tcscat_s(tmpwav, _T("testapp_background.wav"));		// VC2008��VC2010 ���� _tcscat_s ����
	// ��wav ��Դ��ȡΪ��ʱ�ļ�
	//ExtractResource(tmpwav,_T("WAVE"), "background.mp3");
	// ע�����wave��Դ�� ID Ϊ�� IDR_BACKGROUND����������
	ExtractResource(tmpwav, _T("WAVE"), MAKEINTRESOURCE(IDR_WAVE_POINT));
	// ������
	//TCHAR mcicmd[300];
	_stprintf_s(mcicmd, _T("open \"%s\" alias mymusic"),tmpwav);		// VC2008��VC2010 ���� _stprintf_s ����
	//mciSendString(mcicmd, NULL,0, NULL);
	// ��������
	//mciSendString(_T("play mymusic"), NULL, 0, NULL);
	// ֹͣ���Ų��ر�����
	//mciSendString(("stop mymusic"), NULL, 0, NULL);
	//mciSendString(("close mymusic"), NULL, 0, NULL);
	// ɾ����ʱ�ļ�
	//DeleteFile(tmpmp3);
}