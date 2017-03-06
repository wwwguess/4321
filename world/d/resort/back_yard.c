inherit ROOM;

void create()
{
        set("short", "山庄后院");
        set("long", @LONG
庄外的小溪在这里形成一个小小的瀑布。这里的景色美不胜收。
东边的小屋中藏着很多形形色色的武功秘笈，是铁雪庄主一生的积
蓄。西边则是一个小小的练功室。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"bamboo_hall",
  "east" : __DIR__"bookhouse",
  "west" : __DIR__"exerhouse",
]));
        set("blocks", ([
  "east" : "oldguy",
]));

       set("objects", ([
                __DIR__"npc/w_guy" : 1,
                __DIR__"npc/b_guy" : 1,
        ]) );
        set("outdoors", "resort");

        setup();
}
