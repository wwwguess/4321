
inherit ROOM;

void create()
{
        set("short", "城门");
        set("long", @LONG
石砌的城垣横布在布达拉宫和恰克卜里山之间。城门在一座舍利塔下。
塔里藏着历代高僧的佛骨和无数神秘美丽的传说与神话。气势迫人的宫殿
毅然出现在你的面前。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"octostreet",
  "east" : __DIR__"grassland4",
  "up"   : __DIR__"topoftower",
]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/cityguard" : 2,
        ]) );
        setup();
}

