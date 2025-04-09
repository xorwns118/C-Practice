#pragma once

// 정적변수
static int g_iStatic = 0;
// static 키워드를 사용하면 Data 영역에 저장. 현재 파일에서만 사용 가능

// 외부변수
// 초기 값을 넣으면 안됨.
// "이러한 변수가 있을거다" 라는 뜻
extern int g_iExtern;
// 어딘가에서는 값이 초기화 되어야 함.