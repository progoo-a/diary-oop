/**
 * Une classe `User` peut s'abonner à un flux d'information `News`.
 * Lorsqu'une nouvelle est publiée les utilisateurs sont notifiés:
 *
 * - `User` est un `Subscriber` qui dispose d'une méthode `update()`
 * - `News` est un `Publisher` qui dispose d'une méthode `subscribe()`
 *    et `notifySubscribers()`
 * - `News` dispose d'une méthode `publish(std::string news)` qui insert
 *    une nouvelle information et notifie tous les abonnés.
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Subscriber {
public:
    virtual void update(std::string news) = 0;
};

class Publisher {
public:
    virtual void subscribe(Subscriber *subscriber) = 0;
    virtual void notifySubscribers() = 0;
};

class News : public Publisher {
    std::vector<Subscriber *> subscribers;
    std::string news;
public:
    void subscribe(Subscriber *subscriber) override { subscribers.push_back(subscriber); }
    void notifySubscribers() override {
        for (auto subscriber : subscribers) {
            subscriber->update(news);
        }
    }
    void publish(std::string news) {
        this->news = news;
        notifySubscribers();
    }
};

class User : public Subscriber {
    std::string name;
public:
    User(std::string name) : name(name) {}
    void update(std::string news) override { std::cout << name << " received: " << news << std::endl; }
};

int main() {
    News news;
    std::vector<User> users;
    users.emplace_back("user1");
    users.emplace_back("user2");
    users.emplace_back("user3");
    for (auto &user : users)
        news.subscribe(&user);

    news.publish("Hello World!");
}
