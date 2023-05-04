
// MFC3View.cpp: CMFC3View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC3.h"
#endif

#include "MFC3Doc.h"
#include "MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BOOL exitFlag = TRUE;  //SDIIView.cpp의 맨 앞부분에 복사
UINT ThreadProc(LPVOID lParam)
{
	CBrush cBrush, * oldBrush;
	CDC* pDC;
	RECT rect;
	int    xLeft, xRight, yTop, yBottom, iRed, iGreen, iBlue;
	CSDIIView* pView;
	pView = (CSDIIView*)lParam;
	pView->GetClientRect(&rect);
	pDC = pView->GetDC();
	while (TRUE)
	{
		xLeft = rand() % rect.right;
		xRight = rand() % rect.right;
		yTop = rand() % rect.bottom;
		yBottom = rand() % rect.bottom;
		iRed = rand() & 255;
		iGreen = rand() & 255;
		iBlue = rand() & 255;
		cBrush.CreateSolidBrush(RGB(iRed, iGreen, iBlue));
		oldBrush = pDC->SelectObject(&cBrush);
		pDC->Rectangle(min(xLeft, xRight), min(yTop, yBottom), max(xLeft, xRight), max(yTop, yBottom));
		pDC->SelectObject(oldBrush);
		cBrush.DeleteObject();
		if (exitFlag)  break;
	}
	pView->ReleaseDC(pDC);
	return 0;
}


IMPLEMENT_DYNCREATE(CMFC3View, CView)

BEGIN_MESSAGE_MAP(CMFC3View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DRAWBOX, &CMFC3View::OnDrawbox)
	ON_COMMAND(ID_THREAD_START, &CMFC3View::OnThreadStart)
	ON_COMMAND(ID_THREAD_END, &CMFC3View::OnThreadEnd)
END_MESSAGE_MAP()

// CMFC3View 생성/소멸


CMFC3View::CMFC3View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC3View::~CMFC3View()
{
}

BOOL CMFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC3View 그리기

void CMFC3View::OnDraw(CDC* pDC)
{
	CMFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CString test = _T("Hello MFC SDI GDI interface test!!");
	pDC->TextOut(100, 100, test);

	//CMFC3Doc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	//CMFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//Polyline와 PolyBezier에 사용할 POINT배열 
	POINT pline[6] = { 50,133,146,99,246,133,247,212,58,216,50,133 };
	//다각형 칠하기에 사용할 POINT배열
	POINT pgon[4] = { 308,120,440,118,380,212,308,120 };
	RECT rect;
	CBrush cBrush, * oldBrush;
	//RoundRect에 사용할 모서리 둥근원의 x,y지름
	POINT round = { 50,50 };
	//브러쉬를 노랑색 브러쉬로 만든다
	cBrush.CreateSolidBrush(RGB(255, 255, 0));
	//클라이언트 영역을 얻는다.
	GetClientRect(&rect);
	//라운드 박스를 그린다.
	pDC = GetDC();//DC를 얻고
	pDC->RoundRect(&rect, round);
	//윈을 그린다.
	pDC->Ellipse(rect.left + 30, rect.top + 30,
		rect.right - 30, rect.bottom - 30);
	//0,0좌표에서 화면 전체에 대각선을 그린다.
	pDC->MoveTo(0, 0);
	pDC->LineTo(rect.right, rect.bottom);
	//다각형 외곽선을 그린다.
	pDC->Polyline(pline, 6);
	//베지어 곡선을 그린다.
	pDC->PolyBezier(pline, 4);
	//브러쉬를 설정하고
	oldBrush = pDC->SelectObject(&cBrush);
	//내부를 칠하는 다각형을 그린다.
	pDC->Polygon(pgon, 4);
	//이전 브러쉬를 설정하고
	pDC->SelectObject(oldBrush);
	//브러쉬를 삭제한다.
	cBrush.DeleteObject();
}


// CMFC3View 인쇄

BOOL CMFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFC3View 진단

#ifdef _DEBUG
void CMFC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3Doc* CMFC3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3Doc)));
	return (CMFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3View 메시지 처리기


void CMFC3View::OnDrawbox()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.


}


void CMFC3View::OnUpdateThreadStart(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	if (exitFlag)pCmdUI->Enable(TRUE);
	else pCmdUI->Enable(FALSE);

}


void CMFC3View::OnUpdateThreadEnd(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!exitFlag)pCmdUI->Enable(TRUE);
	else pCmdUI->Enable(FALSE);



}


void CMFC3View::OnThreadStart()
{
	exitFlag = FALSE;
	AfxBeginThread(ThreadProc, (LPVOID)this);
}


void CMFC3View::OnThreadEnd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	exitFlag = TRUE;
}

