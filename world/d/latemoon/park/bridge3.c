inherit ROOM;

void create()
{
   set("short", "��������");
	set("long", @LONG
�������ϣ�����Զ��ɽ�����������߷�¥��գ����Ρ�������
��ͤ԰��ľ֮�䣻������֮��������кѩʯ�㴩�ơ������ʯΪ��
���������أ��������ߣ����µ�ϼ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "south" :__DIR__"moon4",
       "northwest" :__DIR__"moon1",

]));

	setup();
	replace_program(ROOM);
}
