/**
 * @file primeNumber.cpp
 * @brief 素数の計算サンプル
 */

#include <iostream>
#include <deque>
#include <unistd.h>
#include <cstring>
using namespace std;

/**
 * 素数判定処理
 * @brief 入力値 n が素数であるかを判定する
 * @param [in]n   判定対象の値
 * @param [in]pn 既知の素数のリスト
 * @retval true  素数である
 * @retval false 素数でない
 * @detail
 * この関数は、nが素数であるかどうかをpnの値を使って
 * 調べる。nが素数であるかを正しく判定する為には、
 * n-1 以下の素数を予め全てpnに格納する必要が有る。
 */
template <typename C>
static inline bool isPn(size_t n, const C & pn)
{
	bool div = true;
	//! 素数リストに有る数でnが割り切れた場合
	//! 素数でない（false）を返す。
	//! それ以外は 素数である（true）を返す
	for(auto&& x :pn)
	{
		if(n % x == 0)
		{
			div=false;
			break;
		}
	}
	return div;
}

/**
 * 素数の計算サンプル メイン処理
 * @brief 素数の計算、表示を行う
 * @param [in]argc 引数の数
 * @param [in]argv 引数配列
 * @return 常に0を返す
 */
int main(int argc, char *argv[])
{
	//! option
	int opt;
	//! 素数リスト
	deque<size_t> pn;
	//! 素数チェック対象の一時変数 
	size_t n;
	size_t limit = SIZE_MAX;
	while((opt = getopt(argc, argv, "l:")) >= 0)
	{
		switch(opt)
		{
			case 'l':
			limit = (size_t)strtoull(optarg, nullptr, 0);
			break;
		}
	}
	
	
	//! 初期値:2(最小の素数)
	//! nが上限以下の間ループ
	for(n=2; n < limit; n++)
	{
		if(isPn(n,pn))
		{
			//! nが素数なら、素数リストに追加して画面に表示する。
			pn.push_back(n);
			cout << n << endl;
		}
	}
	return 0;
}
