// Room: /d/oldpine/path3.c
#include <room.h>

inherit ROOM;

string look_stone();

void create()
{
	set("short", "����ͨ��");
	set("long", @LONG
    ��������վ��һ����ɭɭ��ɽ��֮��, һ���������ŵĽ�������,
������һ��ͻ���Ĵ���ʯ(stone)��, ����������η, Ҳ����û�ͷ�����ˡ�
LONG
	);

	set("item_desc", ([
		"stone" : (: look_stone :),
	]));

        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"secrectpath1",
        ]));

//	set("no_clean_up", 0);

	setup();
//	replace_program(ROOM);
}

string look_stone ()
{
	return ("һ����˻��ߵ�����ʯ, ��Ȼ��������̦, ����(climb)��ȥ
Ӧ�ò���̫���ѡ�\n");
}

void init()
{
	add_action ("do_climb", "climb");
}

int do_climb(string arg)
{
	if (!arg || arg != "up")
		return notify_fail("ֻ������(up)��һ������\n");

	message_vision ("$N���������ϴ���ʯ��\n", this_player());
	this_player()->move (__DIR__"stone");
}
