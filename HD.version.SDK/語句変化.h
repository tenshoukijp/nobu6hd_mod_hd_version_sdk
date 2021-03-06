#pragma once




// 00（相手に敬意を払う必要がない場合の自称） 
String^ ％わし％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 02（その他の場合の自称） 
String^ ％私％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 03（所有形容詞）  
String^ ％我が％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 04〜07 相手をさげすむ場合「以外」の二人称
String^ ％相手％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 08 相手をさげすむ場合の二人称
String^ ％罵倒相手％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 09〜0D 三名をさげすむ場合「以外」の三人称
String^ ％三名％(int 第１人称_武将番号, int 第２人称_武将番号, int 第３人称_武将番号);

// 0E（第三者をさげすむ場合の三人称） 
String^ ％罵倒三名％(int 第１人称_武将番号, int 第２人称_武将番号, int 第３人称_武将番号);






// 0F 〜です 〜だ じゃ
String^ ％です％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 11 〜ですか 〜でござるか 〜か
String^ ％ですか％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 13 〜でしょう 〜じゃろう 〜であろう 〜だろう
String^ ％でしょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 15 〜でした 〜じゃった 〜であった 〜だった
String^ ％でした％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 17 〜あります 〜ございます 〜ござる 〜ある 〜おじゃる
String^ ％あります％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 19 〜ありません 〜ございません 〜ござらぬ 〜ない 〜おじゃらぬ 〜ありませぬ
String^ ％ありません％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 1B 〜します 〜いたす 〜する
String^ ％します％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 1D 〜しません 〜いたさぬ 〜せぬ 〜せん 〜しませぬ
String^ ％しません％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 1F 〜しましょう 〜いたそう 〜しよう
String^ ％しましょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);


// 21 〜いましょう 〜おう  (言いましょうなど)
String^ ％いましょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 23 〜きましょう 〜こう  (行きましょうなど)
String^ ％きましょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 25 〜しましょう 〜そう  (？… ％しましょう％の方が良いか)
String^ ％しましょう２％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 27 〜ちましょう 〜とう  (待ちましょうなど)
String^ ％ちましょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 29 〜みましょう 〜もう  (攻め込みましょうなど)
String^ ％みましょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 2B 〜ましょう 〜よう  (その他の一般パターン。立てましょうなど)
String^ ％ましょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 2D 〜りましょう 〜ろう  (参りましょうなど)
String^ ％りましょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 31 〜ぎましょう 〜ごう  (急ぎましょうなど)
String^ ％ぎましょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 33 〜びましょう 〜ぼう　(遊びましょうなど)
String^ ％びましょう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);


// 35 〜います 〜ござる 〜おる 〜いる 〜おじゃる 〜おります
String^ ％います％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 37 〜いません 〜ござらぬ 〜おらぬ 〜おらん 〜おじゃらぬ 〜おりませぬ
String^ ％いません％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 39 〜いました 〜ござった 〜おった 〜いた 〜おじゃった 〜おりました
String^ ％いました％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 3B 〜ます 〜る 〜ります
String^ ％ます％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 3D 〜りません 〜らぬ
String^ ％りません％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 3F 〜ません 〜ぬ 〜ねえ 〜ませぬ
String^ ％ません％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 41 〜ました 〜た
String^ ％ました％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 43 〜りました 〜った
String^ ％りました％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 45 〜ませんでした 〜なかった
String^ ％ませんでした％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 47 〜思います 〜存じます 〜思う
String^ ％思います％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 49 〜参りました 〜参上しました 〜参った
String^ ％参りました％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 4B 〜くだされ 〜下さい 〜くれ
String^ ％くだされ％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 4D 〜すみません 〜申し訳ない 〜すまぬ 〜すまん 〜ごめんなさい
String^ ％すみません％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 4F 〜願います 〜お願いいたす 〜願おう 〜願う 〜お願いします
String^ ％願います％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 51 〜よい 〜よろしい
String^ ％よい％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);









// 〜か 〜ね
String^ ％か（１）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜か 〜なの
String^ ％か（２）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜か 〜わ
String^ ％か（３）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜か 〜かしら
String^ ％か（４）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜ぞ 〜ぜ 〜ぞよ 〜わ
String^ ％ぞ（１）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜ぞ 〜ぜ 〜ぞよ 〜わよ
String^ ％ぞ（２）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜な 〜わ
String^ ％な（１）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜な 〜ね
String^ ％な（２）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜(無し) 〜わ
String^ ％わ（１）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜わ 〜わい
String^ ％わ（２）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜なあ 〜のお 〜ねえ 
String^ ％なあ％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜お 〜(無し)
String^ ％お（１）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜お 〜(無し)
String^ ％お（２）％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// ははは ふふふ くくく あはは わはは ふっ うふふ おほほ 
String^ ％ははは％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 〜い 〜き
String^ ％い％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// うむむ まあ 
String^ ％うむむ％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// おお まあ
String^ ％おお％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// つまらぬ… おもしろくありません 
String^ ％つまらぬ％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// やっ し 
String^ ％やっ％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// ち てし
String^ ％ち％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// れ られよ 
String^ ％れ％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// しんぜよう くれよう しんぜましょう 
String^ ％しんぜよう％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// 一族 親子 姉妹 姉弟 兄妹 夫婦 兄弟 姉妹 姉弟 兄妹 
String^ ％一族％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// でござる だぞ、ははは でおじゃるぞえ ですわ 
String^ ％でござる％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// すな しますな 
String^ ％すな％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// てみよ なさい
String^ ％てみよ％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);

// よ ませ
String^ ％よ％(int 第１人称_武将番号, int 第２人称_武将番号 = 0xFFFF, int 第３人称_武将番号 = 0xFFFF);


















public ref class 語句変化情報型 {
public:

	// 00（相手に敬意を払う必要がない場合の自称） 
	String^ わし(噴出メッセージパラメタ型^ パラメタ);

	// 02（その他の場合の自称） 
	String^ 私(噴出メッセージパラメタ型^ パラメタ);

	// 03（所有形容詞）  
	String^ 我が(噴出メッセージパラメタ型^ パラメタ);

	// 04〜07 相手をさげすむ場合「以外」の二人称
	String^ 相手(噴出メッセージパラメタ型^ パラメタ);

	// 08 相手をさげすむ場合の二人称
	String^ 罵倒相手(噴出メッセージパラメタ型^ パラメタ);

	// 09〜0D 三名をさげすむ場合「以外」の三人称
	String^ 三名(噴出メッセージパラメタ型^ パラメタ);

	// 0E（第三者をさげすむ場合の三人称） 
	String^ 罵倒三名(噴出メッセージパラメタ型^ パラメタ);



	// 0F 〜です 〜だ じゃ
	String^ です(噴出メッセージパラメタ型^ パラメタ);

	// 11 〜ですか 〜でござるか 〜か
	String^ ですか(噴出メッセージパラメタ型^ パラメタ);

	// 13 〜でしょう 〜じゃろう 〜であろう 〜だろう
	String^ でしょう(噴出メッセージパラメタ型^ パラメタ);

	// 15 〜でした 〜じゃった 〜であった 〜だった
	String^ でした(噴出メッセージパラメタ型^ パラメタ);

	// 17 〜あります 〜ございます 〜ござる 〜ある 〜おじゃる
	String^ あります(噴出メッセージパラメタ型^ パラメタ);

	// 19 〜ありません 〜ございません 〜ござらぬ 〜ない 〜おじゃらぬ 〜ありませぬ
	String^ ありません(噴出メッセージパラメタ型^ パラメタ);

	// 1B 〜します 〜いたす 〜する
	String^ します(噴出メッセージパラメタ型^ パラメタ);

	// 1D 〜しません 〜いたさぬ 〜せぬ 〜せん 〜しませぬ
	String^ しません(噴出メッセージパラメタ型^ パラメタ);

	// 1F 〜しましょう 〜いたそう 〜しよう
	String^ しましょう(噴出メッセージパラメタ型^ パラメタ);


	// 21 〜いましょう 〜おう  (言いましょうなど)
	String^ いましょう(噴出メッセージパラメタ型^ パラメタ);

	// 23 〜きましょう 〜こう  (行きましょうなど)
	String^ きましょう(噴出メッセージパラメタ型^ パラメタ);

	// 25 〜しましょう 〜そう  (？… ％しましょう％の方が良いか)
	String^ しましょう２(噴出メッセージパラメタ型^ パラメタ);

	// 27 〜ちましょう 〜とう  (待ちましょうなど)
	String^ ちましょう(噴出メッセージパラメタ型^ パラメタ);

	// 29 〜みましょう 〜もう  (攻め込みましょうなど)
	String^ みましょう(噴出メッセージパラメタ型^ パラメタ);

	// 2B 〜ましょう 〜よう  (その他の一般パターン。立てましょうなど)
	String^ ましょう(噴出メッセージパラメタ型^ パラメタ);

	// 2D 〜りましょう 〜ろう  (参りましょうなど)
	String^ りましょう(噴出メッセージパラメタ型^ パラメタ);

	// 31 〜ぎましょう 〜ごう  (急ぎましょうなど)
	String^ ぎましょう(噴出メッセージパラメタ型^ パラメタ);

	// 33 〜びましょう 〜ぼう　(遊びましょうなど)
	String^ びましょう(噴出メッセージパラメタ型^ パラメタ);


	// 35 〜います 〜ござる 〜おる 〜いる 〜おじゃる 〜おります
	String^ います(噴出メッセージパラメタ型^ パラメタ);

	// 37 〜いません 〜ござらぬ 〜おらぬ 〜おらん 〜おじゃらぬ 〜おりませぬ
	String^ いません(噴出メッセージパラメタ型^ パラメタ);

	// 39 〜いました 〜ござった 〜おった 〜いた 〜おじゃった 〜おりました
	String^ いました(噴出メッセージパラメタ型^ パラメタ);

	// 3B 〜ます 〜る 〜ります
	String^ ます(噴出メッセージパラメタ型^ パラメタ);

	// 3D 〜りません 〜らぬ
	String^ りません(噴出メッセージパラメタ型^ パラメタ);

	// 3F 〜ません 〜ぬ 〜ねえ 〜ませぬ
	String^ ません(噴出メッセージパラメタ型^ パラメタ);

	// 41 〜ました 〜た
	String^ ました(噴出メッセージパラメタ型^ パラメタ);

	// 43 〜りました 〜った
	String^ りました(噴出メッセージパラメタ型^ パラメタ);

	// 45 〜ませんでした 〜なかった
	String^ ませんでした(噴出メッセージパラメタ型^ パラメタ);

	// 47 〜思います 〜存じます 〜思う
	String^ 思います(噴出メッセージパラメタ型^ パラメタ);

	// 49 〜参りました 〜参上しました 〜参った
	String^ 参りました(噴出メッセージパラメタ型^ パラメタ);

	// 4B 〜くだされ 〜下さい 〜くれ
	String^ くだされ(噴出メッセージパラメタ型^ パラメタ);

	// 4D 〜すみません 〜申し訳ない 〜すまぬ 〜すまん 〜ごめんなさい
	String^ すみません(噴出メッセージパラメタ型^ パラメタ);

	// 4F 〜願います 〜お願いいたす 〜願おう 〜願う 〜お願いします
	String^ 願います(噴出メッセージパラメタ型^ パラメタ);

	// 51 〜よい 〜よろしい
	String^ よい(噴出メッセージパラメタ型^ パラメタ);



	// 〜か 〜ね
	String^ か_１(噴出メッセージパラメタ型^ パラメタ);

	// 〜か 〜なの
	String^ か_２(噴出メッセージパラメタ型^ パラメタ);

	// 〜か 〜わ
	String^ か_３(噴出メッセージパラメタ型^ パラメタ);

	// 〜か 〜かしら
	String^ か_４(噴出メッセージパラメタ型^ パラメタ);

	// 〜ぞ 〜ぜ 〜ぞよ 〜わ
	String^ ぞ_１(噴出メッセージパラメタ型^ パラメタ);

	// 〜ぞ 〜ぜ 〜ぞよ 〜わよ
	String^ ぞ_２(噴出メッセージパラメタ型^ パラメタ);

	// 〜な 〜わ
	String^ な_１(噴出メッセージパラメタ型^ パラメタ);

	// 〜な 〜ね
	String^ な_２(噴出メッセージパラメタ型^ パラメタ);

	// 〜(無し) 〜わ
	String^ わ_１(噴出メッセージパラメタ型^ パラメタ);

	// 〜わ 〜わい
	String^ わ_２(噴出メッセージパラメタ型^ パラメタ);

	// 〜なあ 〜のお 〜ねえ 
	String^ なあ(噴出メッセージパラメタ型^ パラメタ);

	// 〜お 〜(無し)
	String^ お_１(噴出メッセージパラメタ型^ パラメタ);

	// 〜お 〜(無し)
	String^ お_２(噴出メッセージパラメタ型^ パラメタ);

	// ははは ふふふ くくく あはは わはは ふっ うふふ おほほ 
	String^ ははは(噴出メッセージパラメタ型^ パラメタ);

	// 〜い 〜き
	String^ い(噴出メッセージパラメタ型^ パラメタ);

	// うむむ まあ 
	String^ うむむ(噴出メッセージパラメタ型^ パラメタ);

	// おお まあ
	String^ おお(噴出メッセージパラメタ型^ パラメタ);

	// つまらぬ… おもしろくありません 
	String^ つまらぬ(噴出メッセージパラメタ型^ パラメタ);

	// やっ し 
	String^ やっ(噴出メッセージパラメタ型^ パラメタ);

	// ち てし
	String^ ち(噴出メッセージパラメタ型^ パラメタ);

	// れ られよ 
	String^ れ(噴出メッセージパラメタ型^ パラメタ);

	// しんぜよう くれよう しんぜましょう 
	String^ しんぜよう(噴出メッセージパラメタ型^ パラメタ);

	// 一族 親子 姉妹 姉弟 兄妹 夫婦 兄弟 姉妹 姉弟 兄妹 
	String^ 一族(噴出メッセージパラメタ型^ パラメタ);

	// でござる だぞ、ははは でおじゃるぞえ ですわ 
	String^ でござる(噴出メッセージパラメタ型^ パラメタ);

	// すな しますな 
	String^ すな(噴出メッセージパラメタ型^ パラメタ);

	// てみよ なさい
	String^ てみよ(噴出メッセージパラメタ型^ パラメタ);

	// よ ませ
	String^ よ(噴出メッセージパラメタ型^ パラメタ);

};