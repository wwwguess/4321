
inherit ROOM;

void create()
{
     set("short", "�ͷ�");
	set("long", @LONG
����һ��ͷ������߰���һ��С�輸������Ĳʻ�ƿ�в���һ��
�����輸�����ŵ����Ρ�������������ľ���Ϊ����ׯ���������
��һ���᷿��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "north" :__DIR__"two1",

]));

    set("objects", ([
        __DIR__"npc/guest" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
