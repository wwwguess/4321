// Room: /d/quanzhou/shangu.c
// Date: nov 3, 97   diablo

inherit ROOM;

void create()
{
	set("short", "�ݴ�");
	set("long", @LONG
 �����ǻĹȵĶ��棬һ���ݷ��¹µ����������ڻĹȵľ�ͷ����
��ң����һ��Сɽ�£������ʱ���������ɽ����������������Ϲ�
����������˵���������أ������Ǻڳ���.
LONG
	);

	set("exits", ([ 
                "southdown" : __DIR__ "shangu",
	]));

	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

