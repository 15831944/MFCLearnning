// MyButton.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "09_���ܵİ�ť.h"
#include "MyButton.h"


// MyButton

IMPLEMENT_DYNAMIC(MyButton, CButton)

MyButton::MyButton()
{

}

MyButton::~MyButton()
{
}


BEGIN_MESSAGE_MAP(MyButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// MyButton ��Ϣ�������




void MyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	int x = rand() % (m_w-100);

	int y = rand() % (m_h-100);

	CPoint pt(x, y);

	this->MoveWindow(pt.x, pt.y, 100, 100);


	CButton::OnMouseMove(nFlags, point);
}
