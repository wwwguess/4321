// void.c (re-created after Elon screwed it up on 07-24-95)

inherit ROOM;

void create()
{
        set("short","神秘大森林");
	set("long",@LONG	
这是一片大森林，透着一种神秘的气息！
    四周有许多高入云霄的参天大树(tree),古老的无法叫出它们的名字！
　　森林里特别静，你听着自己的脚步声，感觉自己的心彭彭地跳动着！
　　你不禁毛骨悚然！！！
LONG
	);
        set("objects",([
        __DIR__"obj/red" :random(2),
        __DIR__"obj/green" :random(2)+1,
        ]));
        set("item_desc",([
            "tree":"你听到几声野兽的嚎叫，急忙小心地四处张望。\n",
        ]));
        set("exits",([
        "south" : __DIR__"out-hohai",
        "north" : __DIR__"out-hohai",
        "west":"/d/road/jinling"
        ]));
	setup();
}

