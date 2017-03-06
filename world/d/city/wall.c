// Room: /d/city/wall.c

inherit ROOM;

int do_jump (string arg);

void create()
{
	set("short", "Ժǽ");
	set("long", @LONG
�����������鸮��Ժǽ��ǽ�������������ģ�����
���֡���������ȥ(jump in)�����ǻ�ȥ(jump out)�أ�
LONG
	);

	set("exits", ([
		]));

	set("objects", ([
		]) );

	set("no_clean_up", 0);

	setup();
}

void init ()
{
	add_action("do_jump", "jump");
}

int do_jump (string arg)
{
	if (arg == "in")  {
		this_player()->move(__DIR__"shangshu/feiwu");
		return 1;
		}
	    else if (arg == "out") {
		this_player()->move(__DIR__"street3");
		return 1;
		}
	
	return 0;
}	
