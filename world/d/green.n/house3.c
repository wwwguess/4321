// Mon  08-21-95

inherit ROOM;

string call_spider();

int num_of_spider;

void create()
{
	set("short", "民宅");
	set("long", @LONG
这是一间民宅, 屋内除了一张石床外其他一无所有. 昏暗的屋
内看来死气沉沉的, 似乎这屋子的主人很久没回来了. 屋角有一张
形状很奇怪的蜘蛛网(web).

LONG
	);
    set("exits", ([
    "south" : __DIR__"field1",
]));
	set("no_clean_up", 0);
	set("item_desc", ([
    "web" : (: call_spider :),
	]) );

	setup();
	reset();
}

void reset()
{
	::reset();
	num_of_spider = 3;
}

string call_spider()
{
	object ob;
    if (num_of_spider == 0) return "一张很大的蜘蛛网.\n";
	num_of_spider --;
    ob = new(__DIR__"npc/spider");
    ob->move(__DIR__"house3");
	return "突然你觉得头上有个阴影, 不自觉的抬起头来一看 ............"+
	"好大的 ..... 蜘蛛..... \n";
}
