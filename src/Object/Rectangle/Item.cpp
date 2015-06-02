#include <Factory/Factory.h>
#include <Registry/ObjectRegistry.h>

Item::Item(glm::vec2 position) : Rectangle() {
    Factory<ITextureLoader> textureFactory = Factory<ITextureLoader>();
    ITextureLoader* textureLoader = textureFactory.Create("TextureLoader");
    SetSurface(textureLoader->Load("data/img/Item.png"));
    SetWidth(0.03f);
    SetHeight(0.03f);
    SetPosition(position);
}

bool Item::Idle(float elapsedTime) {
    if (GetLastTime() == 0.0f)
    {
        Rectangle::Idle(elapsedTime);
    }

    float deltaTime = elapsedTime - GetLastTime();

    Move(glm::vec2(0.0f, -0.3f) * deltaTime);
    Rectangle::Idle(elapsedTime);

    return IsOutOfMap();
}

void Item::Activate() {
    ObjectRegistry<Item>::Instance()->Unregister(this);
}
