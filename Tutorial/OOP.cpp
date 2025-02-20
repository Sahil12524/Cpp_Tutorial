/*
    Getting started with OOP -> Object Oriented Programming :P
*/

#include <iostream>
#include <list>

class YoutubeChannel
{
    // private by default and can only be accessed within this class.
    mutable int SubscribersCount; // allows modification even in const function.
    std::string name;
    std::list<std::string> publishedVideosTitle;

protected: // Anything in protected can be accessed by derived class but not from everwhere.
    std::string ownerName;
    int contentQuality;

public: // Anything in public can be accessed outside of the class.
    // constructor but parameterized. AKA not default constructor.
    YoutubeChannel(const std::string &name,
                   const std::string &ownerName)
        : name(name), ownerName(ownerName),     // Initialize members in initializer list
          SubscribersCount(0), contentQuality(0)
    {
    }

    virtual ~YoutubeChannel()
    {
    }

    void getInfo() const
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "Owner Name: " << ownerName << "\n";
        std::cout << "Subscribers Count: " << SubscribersCount << "\n";
        std::cout << "Videos: \n";
        for (const auto &videoTitle : publishedVideosTitle)
        {
            std::cout << videoTitle << "\n";
        }
    }

    void subscribe()
    {
        SubscribersCount++;
    }

    void unsubscribe()
    {
        if (SubscribersCount > 0)
        {
            SubscribersCount--;
        }
    }

    void publishVideo(const std::string &title)
    {
        publishedVideosTitle.push_back(title);
    }

    void checkAnalytics() const
    {
        if (contentQuality < 5)
        {
            std::cout << name << " has bad quality content.\n";
        }
        else
        {
            std::cout << name << " has great content.\n";
        }
    }
};

class CookingYoutubeChannel : public YoutubeChannel
{
public:
    CookingYoutubeChannel(const std::string &name,
                          const std::string &ownerName)
        : YoutubeChannel(name, ownerName)
    {
    }

    void practice()
    {
        std::cout << ownerName << " is practicing cooking, learning new recipes, experimenting with spices...\n";
        contentQuality++;
    }
};

class SingersYoutubeChannel : public YoutubeChannel
{
public:
    SingersYoutubeChannel(const std::string &name,
                          const std::string &ownerName)
        : YoutubeChannel(name, ownerName)
    {
    }

    void practice()
    {
        std::cout << ownerName << " is taking singing classes, learning new songs, learning how to dance...\n";
        contentQuality++;
    }
};

int main()
{
    YoutubeChannel ytChannel("Sahil Bhandari", "Sahil Bhandari");
    YoutubeChannel ytChannel1("Rohan Makes", "Rohan Wandre");

    CookingYoutubeChannel cookingYtChannel("Rohan Cooks", "Rohan Wandre");
    CookingYoutubeChannel cookingYtChannel1("Chef Sahil", "Sahil Bhandari");

    SingersYoutubeChannel singersYtChannel("Sujal Bhandari", "Sujal Bhandari");

    ytChannel.publishVideo("Minecraft sale buy now!");
    ytChannel.publishVideo("C++ Tutorials");
    ytChannel.publishVideo("CS2 Cheater!");
    ytChannel.publishVideo("GTA5 Live\n");

    ytChannel1.publishVideo("React Native Tutorial");
    ytChannel1.publishVideo("Tailwind CSS Tutorial");
    ytChannel1.publishVideo("Mongo DB Tutorial");
    ytChannel1.publishVideo("Minecraft Live\n");

    ytChannel.subscribe();
    ytChannel.subscribe();
    ytChannel.subscribe();
    ytChannel.subscribe();
    ytChannel.subscribe();
    ytChannel.unsubscribe();

    ytChannel1.subscribe();
    ytChannel1.subscribe();
    ytChannel1.subscribe();
    ytChannel1.subscribe();
    ytChannel1.unsubscribe();

    ytChannel.getInfo();
    ytChannel1.getInfo();

    cookingYtChannel.publishVideo("Varan Bhat");
    cookingYtChannel.publishVideo("Chapati Bhaji");
    cookingYtChannel.publishVideo("Fried Rice");
    cookingYtChannel.practice();
    cookingYtChannel.subscribe();
    cookingYtChannel.subscribe();
    cookingYtChannel.subscribe();
    cookingYtChannel.subscribe();
    cookingYtChannel.subscribe();
    cookingYtChannel.subscribe();
    cookingYtChannel.getInfo();

    cookingYtChannel1.practice();
    cookingYtChannel1.getInfo();

    singersYtChannel.practice();
    singersYtChannel.practice();
    singersYtChannel.practice();
    singersYtChannel.practice();
    singersYtChannel.practice();
    singersYtChannel.practice();
    singersYtChannel.practice();
    singersYtChannel.practice();
    singersYtChannel.practice();
    singersYtChannel.practice();

    // Variables of base class can point to variable of derived class.
    YoutubeChannel *yt = &cookingYtChannel;
    YoutubeChannel *yt1 = &singersYtChannel;

    yt->checkAnalytics();
    yt1->checkAnalytics();
    return 0;
}