// Room: /d/choyin/n_street1.c

inherit ROOM;

void create()
{
	set("short", "���ִ��");
	set("long", @LONG
������������һ�����Ľֵ��ϣ������������س���ͨ��������
�ŵĸ��ִ�֣��ֵ�������������ģ������ֻ�ģ�������ϰ��մ��
������ʵʵ��ũ���빤������������Ҳ�����һЩ����Ʒ����������һ
��С���ӣ��ϱߵĽֵ��ƺ��Ƚ�����һЩ���������Ǳ��š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"n_street2",
  "north" : __DIR__"n_gate",
]));
	set("objects", ([
		__DIR__"npc/cake_vendor": 1,
		CLASS_D("beggar") + "/master": 1
	]) );
	set("outdoors", "choyin");

	setup();
	replace_program(ROOM);
}
