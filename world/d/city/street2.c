// Room: /d/city/street2.c

inherit ROOM;

void create()
{
        set("short", "��ʦ����");
        set("long", @LONG
�����ھ�ʦ���ֵ��жΡ���������Ͻ��ǳ�ǽ�����鸮Ժǽ֮��
������ĵ�·ͨ�����ź����鸮�Ĵ��ţ���������Զ����Զ�ֵܾ���
����ϡ�ɼ�����������ԼԼ�ظе�һ��ɱ����
LONG
        );

	set("objects", ([
		__DIR__"npc/walker":	2,
		]) );

        set("exits", ([ 
		"north":	__DIR__"street1",
		"south":	__DIR__"street3",
		]));

        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

