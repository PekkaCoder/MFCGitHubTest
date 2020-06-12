
// MFCGitHubTestView.cpp : implementation of the CMFCGitHubTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCGitHubTest.h"
#endif

#include "MFCGitHubTestDoc.h"
#include "MFCGitHubTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCGitHubTestView

IMPLEMENT_DYNCREATE(CMFCGitHubTestView, CView)

BEGIN_MESSAGE_MAP(CMFCGitHubTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCGitHubTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCGitHubTestView construction/destruction

CMFCGitHubTestView::CMFCGitHubTestView() noexcept
{
	// TODO: add construction code here

}

CMFCGitHubTestView::~CMFCGitHubTestView()
{
}

BOOL CMFCGitHubTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCGitHubTestView drawing

void CMFCGitHubTestView::OnDraw(CDC* pDC)
{
	CMFCGitHubTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOutW(10,10,_T("Version 1"));
	pDC->TextOutW(10, 50, _T("Version 2: This is a title"));
}


// CMFCGitHubTestView printing


void CMFCGitHubTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCGitHubTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCGitHubTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCGitHubTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCGitHubTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCGitHubTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCGitHubTestView diagnostics

#ifdef _DEBUG
void CMFCGitHubTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCGitHubTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCGitHubTestDoc* CMFCGitHubTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCGitHubTestDoc)));
	return (CMFCGitHubTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCGitHubTestView message handlers
