inherit ROOM;

void create()
{
   set("short", "���᷿�ߵ�");
	set("long", @LONG
ͨ�������ߵ����������߽����᷿�ߵ����������ߵ��У�����
�ɵĳ��Ƽ��Ϲ���һ�������Ĺ���! �ߵ����԰���������滨��ݣ�
����������һ�ֵ�������������һ�������λ����ĳ������̻����
�ʻ��ͼ�Σ�����ʤ�ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"lroad3",
    "south" :__DIR__"wroad2",

]));

	setup();
	replace_program(ROOM);
}
