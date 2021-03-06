/**
 * CommandEdit.h
 * An extension of the classic CEdit control to mimic a REPL environment.
 *
 * @author Nathan Campos <nathan@innoveworkshop.com>
 */

#ifndef _COMMANDEDIT_H
#define _COMMANDEDIT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EnvironmentList.h"

/**
 * An extension of the classic CEdit control to mimic a REPL environment.
 */
class CCommandEdit : public CEdit {
protected:
#ifdef _WIN32_WCE
	CWnd *m_pwndParent;
#else
	CDialog *m_pdlgParent;
#endif  // _WIN32_WCE
	CEnvironmentList *m_plstEnvironment;
	CString m_strPrompt;
	env_t *m_pEnv;

	// Expression stuff.
	void HandleExpression();

public:
	// Initialization.
	CCommandEdit();
#ifdef _WIN32_WCE
	void InitializePrompt(CWnd *pwndParent,
		CEnvironmentList& lstEnvironment, env_t *pEnv);
#else
	void InitializePrompt(CDialog *pdlgParent,
		CEnvironmentList& lstEnvironment, env_t *pEnv);
#endif  // _WIN32_WCE

	// Expression operations.
	CString GetCurrentExpression();
	void ExecuteExpression(CString& strExpression);

	// Prompt stuff.
	CString GetPrompt();
	void SetPrompt(CString strPrompt);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommandEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCommandEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCommandEdit)
	afx_msg UINT OnGetDlgCode();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillFocus();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif  // _COMMANDEDIT_H
