= GitHubとRe:VIEWで執筆環境を構築しよう

自分のパソコンに自動組版の環境を作って技術書を書いてみよう。

//pagebreak

== 3日間で書く執筆ハッカソン「Bookathon」

筆者は「技術と本と猫」という執筆支援コミュニティを運営しており、そのコミュニティで「Bookathon（ブッカソン）」というイベントを定期開催しています。

Bookathonは、3日間で技術書を書き上げるハッカソンイベントです。金曜の夜から始めて、日曜の午後には本を完成させます。

「そんな短期間で本なんか書けるの？！」と思われるかもしれませんが、だったら執筆のために長期間を確保できるかと問われたら殆どの人が難しいはずです。「時間ができたら」「いつか機会があれば」と思っていても、技術書を書く時間や機会というものはいつまでも訪れません。

ドアから人が溢れかけているような満員電車でも、「絶対にこれに乗るんだ」と強い気持ちで「すみません、乗ります！」と声をかけてぐっと自分の体を押し込めば、なんとかかんとか乗れてしまうように、時間も機会も強い気持ちで作らないかぎり得られないのです。そして筆者を含め、殆どの人は〆切もないのに頑張れるほど強い精神力がありません。

という訳で、まずは〆切を作りましょう。間に合うかどうかではなく、間に合わせるのです。

間に合わせるためには、「書く」ことに集中せねばなりません。「書く」こと以外の些末な部分に時間を取られていると間に合わなくなります。なので、Bookathonでは執筆環境を書籍執筆ツールのGitHubとRe:VIEW（リビュー）@<fn>{review}の組み合わせで統一しています。

//footnote[review][電子書籍と紙書籍の両方に対応した自動組版のツール。 @<href>{https://reviewml.org/}]

いずれも無料で使用でき、環境構築も1時間程度あれば可能です。あなたも今週末にひとりBookathonをやってみませんか？

== 本の執筆環境を構築する

BookathonではRe:VIEWという書籍制作のためのツールを使用します。MarkdownファイルをデプロイすることでHTMLが生まれるように、原稿をRe:VIEW記法で書いてデプロイすることで「本の見た目」に自動組版されたPDFファイルが生成できます。このPDFは、簡単な設定で電子書籍にも、印刷所に入稿して作る紙書籍にも対応可能です。さらにGitHubも組み合わせて使うことで、原稿の共有やバージョン管理、校正などがやりやすくなります。

この付録では、個人のパソコンにおいて、できるだけ短時間で「本を書く」のに必要な環境を構築することを最優先として手順を解説します。

=== 下準備

GitHubとRe:VIEWを使うために必要な5つの道具を準備しておきましょう。

 1. Visual Studio Code
 2. git
 3. GitHubアカウント
 4. gh
 5. Docker

環境によってそれぞれの道具が既に使える状態であれば、該当するセクションは読み飛ばして構いません。

==== Visual Studio Code（エディタ）をインストールする

Visual Studio Code（以下、VS Code）は原稿を書くためのエディタです。Visual Studio Code公式サイト（@<href>{https://code.visualstudio.com/Download}）から、自身の環境にあったインストーラーをダウンロードします（@<img>{bookathon-vscode-download}）。

//image[bookathon-vscode-download][Visual Studio Codeのダウンロード画面][scale=0.8]{
//}

ダウンロードしたらインストーラーの手順に従ってインストールします。VS Codeが起動したら、左側にある拡張機能の四角いアイコンを開きます。「Japanese Language Pack」を検索してインストールすると、メニューを日本語にできます（@<img>{bookathon-vscode-japanese-pack}）。

//image[bookathon-vscode-japanese-pack][Japanese Language Packのインストール][scale=0.6]{
//}

拡張機能をインストールしたらVS Codeを再起動します。メニューが日本語表示になったVS Codeが起動できたら、VS Codeのインストールは完了です。

==== gitをインストールする

@<tt>{git}は、書いた原稿をGitHubで共有したりするために必要なコマンドです。

Windowsの場合は、Git公式サイトのWindows向けインストールページ（@<href>{https://git-scm.com/install/windows}）にアクセスして、「Click here to download」からインストーラーをダウンロードします（@<img>{bookathon-git-download}）。

//image[bookathon-git-download][Windows用Gitのダウンロード画面][scale=0.7]{
//}

インストーラーの手順に従ってインストールします。gitのインストールができたら、VS Codeを一度閉じてから起動しなおしてください。

起動したVS Codeの上部にあるメニューバーから「表示」＞「ターミナル」を選択して、ターミナルを表示させます。VS Codeのターミナルで次のコマンドを入力してエンターを押し、何かしらのバージョン情報が表示されることを確認してください。

//cmd{
git --version
//}

Windowsの場合、次のように表示されます。バージョン番号は環境によって異なります。

//cmd{
git version ○.○○.○.windows.○
//}

Macの場合も、まずVS Codeの「表示」＞「ターミナル」を開いて、@<tt>{git --version}を実行してください。「gitコマンドを使用するにはコマンドライン・デベロッパーツールが必要です」のようにインストールを促す画面が出たら、そのままインストールします。次のようにバージョン情報が表示されれば準備完了です。

//cmd{
git version ○.○○.○ (Apple Git-○○○)
//}

==== GitHubアカウントを作る

GitHubアカウントは、GitHubで原稿を管理するために必要です。

GitHubのサインアップページ（@<href>{https://github.com/signup}）からアカウントを作ります。この後で使用しますので、登録したユーザーネーム、メールアドレス、そしてパスワードを忘れないようにしてください。

GitHubのプロフィール設定ページ（@<href>{https://github.com/settings/profile}）を開いて、Name（名前）やProfile picture（プロフィール画像）を設定しておきましょう。

==== ghをインストールする

@<tt>{gh}は、ターミナルからGitHubの操作をするために必要なコマンドです。GitHub CLI公式サイト（@<href>{https://cli.github.com/}）からダウンロードし、インストーラーの手順に従ってインストールします。

ghのインストールができたら、VS Codeを一度閉じてから起動しなおしてください。起動したVS Codeの上部にあるメニューバーから「表示」＞「ターミナル」を選択して、ターミナルを表示させます。次のコマンドを入力してエンターを押します。

//cmd{
gh version
//}

次のようにバージョンが表示されたら、ghのインストールは完了です。これは表示例なので、バージョン番号や日付は異なっていても構いません。

//cmd{
gh version 2.87.3 (2026-02-23)
https://github.com/cli/cli/releases/tag/v2.87.3
//}

ghコマンドが使えるようになったら、VS Codeのターミナルで次のコマンドを実行し、GitHubの認証をします。

//cmd{
gh auth login -h github.com -p https -w
//}

 1. 「Authenticate Git with your GitHub credentials? (Y/n)」と聞かれたら、そのままエンターを押します。
 2. 認証方法を選ぶ画面が表示された場合は、「Login with a web browser」を選択してエンターを押します。
 3. 4桁-4桁のワンタイムコード（one-time code）が表示されるので、それをコピーします。
 4. ブラウザでデバイスアクティベーションのページ（@<href>{https://github.com/login/device}）を開くよう案内されたら、エンターを押します。
 5. 自動的にブラウザが立ち上がり、GitHubのデバイスアクティベーション（Device Activation）のページが開きます。「Signed in as ○○」で自分のGitHubアカウントが表示されたら「Continue」を押します。
 6. コピーしておいたワンタイムコードを入力し、「Continue」を押します（@<img>{bookathon-github-device-activation}）。

//image[bookathon-github-device-activation][GitHubのワンタイムコード入力画面][scale=0.6]{
//}

VS Codeのターミナルで「Logged in as ○○」と表示されたら、GitHubの認証も完了です。

==== gitコマンドでユーザー名とメールアドレスを設定する

gitコマンド、GitHubアカウント、ghコマンドの3つが準備できたら、VS Codeのターミナルで次のコマンドを実行します。引用符の中は、自分がGitHubで登録したユーザーネームとメールアドレスに置き換えてください。

//cmd{
git config --global user.name "GitHubのユーザーネーム"
git config --global user.email "GitHubのメールアドレス"
//}

VS Codeのターミナルで次のコマンドを実行して、ユーザーネームとメールアドレスが表示されたら設定は完了です。

//cmd{
git config --global user.name
git config --global user.email
//}

さらにWindowsの場合は、改行コードの自動変換によるエラーを防ぐため、改行コードの設定も行ってください。

//cmd{
git config --global core.autocrlf false
//}

VS Codeのターミナルで次のコマンドを実行して、@<tt>{false}と表示されたら改行コードの設定は完了です。

//cmd{
git config --global --get core.autocrlf
//}

==== Docker Desktopをインストールする

Dockerを使うことで、Re:VIEW記法で書いた原稿からPDFを生成するためのローカル環境をすぐに構築できます。Docker Desktop公式サイト（@<href>{https://www.docker.com/products/docker-desktop/}）から、自身の環境にあったインストーラーをダウンロードします（@<img>{bookathon-docker-download}）。

//image[bookathon-docker-download][Docker Desktopのダウンロード画面][scale=0.6]{
//}

インストーラーの手順に従って、Docker Desktopをインストールします。もしWindows環境で「WSL 2 installation is incomplete」と表示されて、WSL2のインストールを促す画面が出たら、そのままインストールしてください。

Docker Desktopのインストールが完了したら、Docker Desktopを起動します。

=== Re:VIEWのテンプレートで本を書いてみる

道具が揃ったら、次はRe:VIEWを使って本を書くために、テンプレートを自分の手元に用意しましょう。

==== GitHubでテンプレートを使ってリポジトリを作る

GitHubにログインした状態のブラウザで、Re:VIEWテンプレートのリポジトリ（@<href>{https://github.com/TechBooster/ReVIEW-Template}）を開きます。右上にある「Use this template」のボタンから「Create a new repository」をクリックします（@<img>{bookathon-github-use-template}）。

//image[bookathon-github-use-template][テンプレートから新しいリポジトリを作る][scale=0.6]{
//}

「Create a new repository」のページで、Repository ownerを自分のGitHubアカウントにして、name（リポジトリ名）を「sample-book」にします（@<img>{bookathon-github-create-repository}）。

//image[bookathon-github-create-repository][リポジトリの所有者と名前を指定する][scale=0.8]{
//}

「Create repository」のボタンをクリックして少し待ちます。自分用のリポジトリが出来上がると、次のようなURLのページが表示されます。「ユーザーネーム」の部分は自分のGitHubのユーザーネームになります。

//emlist{
https://github.com/ユーザーネーム/sample-book
//}

「<> Code」のボタンからHTTPSのタブを選び、「Copy URL to clipboard」をクリックして、「自分用のリポジトリをクローンするためのURL」をコピーしておいてください（@<img>{bookathon-github-clone-url}）。

//image[bookathon-github-clone-url][自分のリポジトリのクローン用URLをコピーする][scale=1.0]{
//}

==== GitHubのリポジトリをローカルにクローンする

VS Codeの左側のメニューにある「ソース管理」（枝分かれしたアイコン）をクリックして、「リポジトリをクローン」をクリックします（@<img>{bookathon-vscode-clone}）。

//image[bookathon-vscode-clone][VS Codeのソース管理からクローンする][scale=0.6]{
//}

先ほどコピーしておいた「自分用のリポジトリをクローンするためのURL」を貼り付けてエンターを押します（@<img>{bookathon-vscode-clone-url}）。

//image[bookathon-vscode-clone-url][クローンするリポジトリのURLを入力する][scale=0.8]{
//}

クローンしてきたリポジトリをどこに置くか聞かれるので、置き場所となるフォルダを指定して「リポジトリの宛先として選択」を押します（@<img>{bookathon-vscode-clone-destination}）。ここで指定したフォルダの中に@<tt>{sample-book}というフォルダが生成されて、その中にRe:VIEWのファイルが置かれます。

//image[bookathon-vscode-clone-destination][クローン先のフォルダを選択する][scale=0.6]{
//}

指定したフォルダへのクローンが終わると「リポジトリを開きますか？」と表示されるので、「開く」をクリックします（@<img>{bookathon-vscode-open-repository}）。

//image[bookathon-vscode-open-repository][クローンしたリポジトリを開く][scale=0.6]{
//}

VS Codeの左側に@<tt>{sample-book}フォルダの中身が表示されたら、クローンは完了です（@<img>{bookathon-vscode-repository-files}）。

//image[bookathon-vscode-repository-files][クローンしたリポジトリのファイル一覧][scale=0.35]{
//}

原稿のファイルは基本的に@<tt>{articles}フォルダの中にあります。早速、@<tt>{articles}フォルダの中にある著者紹介のファイル（@<tt>{contributors.re}）を開いてみましょう（@<img>{bookathon-vscode-contributors-file}）。ファイルの中の著者名やプロフィールを、自分のものに書き換えて保存します（@<img>{bookathon-vscode-edit-contributors}）。

//image[bookathon-vscode-contributors-file][articlesフォルダのcontributors.reを開く][scale=0.5]{
//}

//image[bookathon-vscode-edit-contributors][著者紹介を自分の名前とプロフィールに書き換える][scale=0.6]{
//}

=== Re:VIEWでPDFを生成してみる

それではRe:VIEWのバージョン5.9の環境が入っているDockerイメージを使って、「本の見た目」に自動組版されたPDFファイルを生成（ビルド）してみましょう。

==== Re:VIEW 5.9のDockerイメージを取得する

実際に本のPDFを生成する前に、Re:VIEW 5.9の執筆環境一式が入った「Dockerイメージ」をインターネットからダウンロードします。VS Codeのターミナルで次のコマンドを実行します。

//cmd{
docker pull vvakame/review:5.9
//}

Dockerイメージはサイズが大きいので数分待ちます。完了したら、次のコマンドを実行してDockerイメージが取得できたことを確認します。@<tt>{vvakame/review}というDockerイメージの名前やサイズが表示されたら、無事取得できています。

//cmd{
docker images vvakame/review
//}

==== PDFをビルドする

すべての準備ができたら、Re:VIEWを使ってPDFファイルを生成してみましょう。VS Codeで@<tt>{sample-book}フォルダを開き、ターミナルの作業フォルダが@<tt>{build-in-docker.sh}のあるリポジトリ直下になっていることを確認してください。

VS Codeのターミナルで次のコマンドを実行して、Re:VIEWでPDFを生成します。生成には数十秒〜数分程度かかります。

//cmd{
bash build-in-docker.sh
//}

@<tt>{articles}フォルダの下に@<tt>{ReVIEW-Template.pdf}が生成されたら、ビルド成功です（@<img>{bookathon-vscode-built-pdf}）。このファイル名はテンプレートの初期設定の場合で、@<tt>{config.yml}の@<tt>{bookname}を変更するとPDFのファイル名も変わります。

//image[bookathon-vscode-built-pdf][articlesフォルダに生成されたPDF][scale=0.3]{
//}

@<tt>{ReVIEW-Template.pdf}を開いて、本の見た目になっているか確認してみましょう。

==== ビルドに失敗するときのトラブルシューティング

 : 「Docker Desktop is not running」と出る
  Docker Desktopが起動されていません。起動してからもう一度ビルドしてみましょう。

 : PDFを削除できないという警告が出る
  「Unable to delete」や「EACCES: permission denied」とともに@<tt>{articles/ReVIEW-Template.pdf}が表示される場合は、先ほど生成されたPDFファイルを開いたままで再度ビルドしようとして失敗している可能性があります。一旦PDFファイルを閉じてからビルドしてください。

=== 原稿を書いてみよう

環境が整ったら、次はいよいよ原稿を書いていきます。

==== どのファイルを編集すればいい？

まずは、VS Codeの左側のファイル一覧から@<tt>{articles}フォルダを見つけてください。主に編集するのは、次のファイルです。

 : @<tt>{catalog.yml}
  本の中身の順番を決める目次設定のファイルです。このファイルを見れば、たとえば「前書きを直したかったら@<tt>{PREDEF}に書かれている@<tt>{preface.re}というファイルを書き換えればいいんだ」と分かります。前書きのファイル名はテンプレートによって異なるので、自分の@<tt>{catalog.yml}を確認してください。最初は@<tt>{CHAPS}の下に第1章に相当する@<tt>{article.re}ファイルしかありませんが、新しいファイル名を書き足して、そのファイルを作ることで第2章以降を作れます（@<img>{bookathon-vscode-catalog}）。

//image[bookathon-vscode-catalog][catalog.ymlで原稿ファイルと掲載順を確認する][scale=0.5]{
//}

 : @<tt>{config.yml}
  本のタイトルや著者名などの奥付を設定するファイルです。

 : @<tt>{article.re}など（@<tt>{.re}ファイル）
  @<tt>{○○.re}が原稿のファイルです。1章につき1ファイルの対応でファイルを作成します。ファイルを作成したら、@<tt>{catalog.yml}にファイル名を書く必要があります。

==== Re:VIEW記法で原稿を書こう

@<tt>{.re}ファイルでどんな風に書いたらPDFでどういう見た目になるのかについては、Re:VIEW フォーマットガイド（@<href>{https://github.com/kmuto/review/blob/master/doc/format.ja.md}）を参照してください。

また、電子版が無料でダウンロードできる「LINE Botをつくってみよう ～APIを試して学んでしっかりわかる～」という本は、原稿のリポジトリがGitHubで公開されています。「この見た目にするには、@<tt>{.re}ファイルでどういう書き方をすればいいんだろう？」という逆引きに使ってみてください。

 * 「LINE Botをつくってみよう」の原稿リポジトリ（@<href>{https://github.com/mochikoAsTech/startLINEBot}）
 * 「LINE Botをつくってみよう」電子版の無料ダウンロード（@<href>{https://techbookfest.org/product/qNMTjpz3LTvmfuE5fRgSZb}）

== 技術書典に申し込んでみよう

その先の申し込みは「届ける工夫」を参照。
