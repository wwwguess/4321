inherit ROOM;

void create()
{
   set("short", "���᷿�ߵ�");
	set("long", @LONG
ͨ�������ߵ����������߽����᷿�ߵ������˳������ߵ��У�
һ�������Ĺ���! �ߵ����԰���������滨��ݣ����и�����ɫ��
��̬������������һ�ֵ���������������ͨ�����᷿��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"lroad1",
    "south" :__DIR__"eroad1",

]));

	setup();
	replace_program(ROOM);
}
