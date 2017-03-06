// Room: /d/death/bridge.c

inherit ROOM;

void create()
{
	set("short", "�κ���");
	set("long", @LONG
��������վ��һ��������ʯ���ϣ���ͷһ��ʯ������������κ���
��������׭�����������涼�Ǵ������ŵ����ǲ���ˮ����������Ũ��
����������ʵ���Ӱ��������ȥ���κ����������쵽һƬ����֮��
����������ԼԼ��һ����¥��Ӱ�ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"gate",
		"south" : __DIR__"bridge1",
	]));
	set("objects", ([
		__DIR__"npc/hell_guard": 4,
	]) );

	setup();
	replace_program(ROOM);
}
