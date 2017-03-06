// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "石场");
        set("long", @LONG
恰克卜里山盛产各种上等石料。这里硝烟弥漫，很多人都在辛苦的劳动着。
用自己的汗水去换取一些收入。每个到这里工作的人都可以拿到一份很公平的
报酬。许多人正在忙忙碌碌的工作着，门口挂著一块牌子(sign)。
LONG
        );
        set("exits", ([/*sizeof() == 1*/
  "north" : __DIR__"octo5",
]));

        set("item_desc", ([
                "sign": @TEXT
现在正紧缺人手，急需雇佣一批短工来干活。

work     开始工作。

TEXT
        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
        setup();
}

void init()
{
        add_action("do_work", "work");
}

int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();
if(((int)me->query("sen") < 30) || ((int)me->query("gin") < 30))
	    {
	     write("$N太累了，还是先歇歇吧\n", me);
	     return 1;
	    }
else
	    {
message_vision("$N辛苦的工作终于结束了，可人也累的要死\n", me);
me->add("gin",-30);
me->add("sen",-30);
//receive_damage("gin",30,me);
//receive_damage("sen",30, me);
ob = new("/obj/money/silver");
ob->move(me);
message_vision("老板对$N说：这是你的工钱。\n", me);
return 1;
	    }
}
