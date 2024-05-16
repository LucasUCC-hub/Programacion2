#include <string>
#include <iostream>

using namespace std;

class Autor {
private:
    string name;
    string photo_url;
public:
    Autor(string _name = "Anonimo", string _photo_url = "https//photos/user.png") : name(_name), photo_url(_photo_url) {}
    string getName() {
        return name;
    }
};


class Tweet {
private:
    int likes;
    string title, content;
    Autor autor;
public:
    Tweet(string _title = "", string _content = "", const Autor& _autor = Autor(), int _likes = 0) : title(_title), content(_content), autor(_autor), likes(_likes) {}
    string getTitle() {
        return title;
    }
    string getContent() {
        return content;
    }
    Autor getAutor() {
        return autor;
    }
    void setTitle(string _title) {
        title = _title;
    }
    void setContent(string _content) {
        content = _content;
    }
    void like() {
        likes++;
    }
};


class TweetPremium : public Tweet {
private:
    int views;
    string tags[3];
public:
    TweetPremium(string _title = "", string _content = "", const Autor& _autor = Autor(), int _likes = 0, int _views = 0, const string (&_tags)[3] = {"", "", ""}) : Tweet(_title, _content, _autor, _likes), views(_views), tags(_tags) {}
    void view() {
        views++;
    }
    void change_tag(int index, string tag) {
        tags[index] = tag;
    }
};

void log(Tweet tweet) {
    cout << tweet.getTitle() << endl << tweet.getContent() << endl << "Autor: " << tweet.getAutor().getName() << endl;
}

#include <iostream>

int main() {
    Tweet t1("Se juega la final", "Ahora si Scaloni...", Autor("Lucas"));
    t1.like();
    t1.like();
    t1.like();

    log(t1);

    cout << endl;

    TweetPremium t2("No da a basto la calefaccion", "Un inquilino en Nueva Cordoba...", Autor("Francho"));
    t2.change_tag(0, "nuevacordoba");
    t2.view();
    t2.view();

    log(t2);
}
