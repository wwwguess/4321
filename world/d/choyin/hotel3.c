// Room: /d/choyin/hotel3.c

inherit ROOM;

void create()
{
	set("short", "���־�¥");
	set("long", @LONG
�����Ǹ��־�¥�Ŀͷ���ס�Ķ���һЩ��������ĸ��̴�֣�Ϊ��
Ԥ����С���Բ�����־�¥�����ƹ��ر�����������ʦ����������
���������¿��Իص���¥��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"hotel2",
	]));
	set("objects", ([
		__DIR__"npc/guard": 3
	]) );

	setup();
	replace_program(ROOM);
}
