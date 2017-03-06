// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "�����ջ");
	set("long", @LONG
��������վ��ѩͤ���ϱߵ�һ��С��ջ���ҿ�ջ��С��ȴ�Ƿ�Բ
��������ʢ����һ�ң���ջ�����˾�˵��һλ�����ĺ������ˣ����
��ĸ�Ե���Ļ���Ҳ�����������������������֮�⣬���Ը��ص�����
��ϲ���ۼ������ｻ����;�ϵļ��ţ���Ҳ��������������������Ȥ��
��Ϣ�������ſڵĵط���һ����ľ��ɵ�����(sign)��
    ��������һ����ľ��(door)�����Ϸ���һ���ɫ�Ĺ��Σ�һ�����˸�
�������������ֺ���͵Ĺ�â��
LONG
	);

	// This enables players to save this room as their startroom.
	set("valid_startroom", 1);

	set("item_desc", ([
		"sign": (: look_sign :),
		"door": (: look_door, "northwest" :),
	]) );
	
	set("exits", ([
		"east"    	: "/d/snow/square",
		"up"		: "/d/snow/inn_2f",
		"northwest"	: "/d/wiz/entrance" ]) );

	set("objects", ([
		"/d/npc/sungoku" : 1,
		"/d/snow/npc/traveller" : 3,
//		"/d/snow/npc/trav_blade" : 3,
                "/d/snow/npc/waiter" : 1 ,]) );

	create_door("northwest", "ľ��", "southeast", DOOR_CLOSED);

	setup();

	// To "load" the board, don't ever "clone" a bulletin board.
	call_other( "/obj/board/common_b", "???" );
}

string look_sign(object me)
{
	if( wizardp(me) )
		return "����д���������ջ���Ա�һ��С�֣�ׯ˼���⡣\n";
	else
		return "����д���������ջ��\n";
}
