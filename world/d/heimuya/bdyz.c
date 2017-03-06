// Room: /d/heimuya/.c
// write by: Www
// date 97/01/25

inherit ROOM;

void create()
{
        set("short","保定驿站");
        set("long", @LONG
这是一个去往北京的专用驿站，交钱就可骑马，速到北京。若向北步行要在京大路
上走半小时。驿站里面有快牌子(sign)。
LONG
        );

        set("exits", ([
		"north" : __DIR__"jbdd",
                "west"  : __DIR__"bdcm",
        ]));

        set("item_desc", ([ 
  		"sign" : "在此交 1 silver 给驿长就可去北京。\n",
	]));

	set("objects", ([
		"/d/heimuya/yizhang1" : 1,
	]));

        set("outdoors", "heimuya");
        setup();
        replace_program(ROOM);
}

