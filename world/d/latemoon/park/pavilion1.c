inherit ROOM;

void create()
{
    set("short", "�߷�ͤ");
	set("long", @LONG
ͤ��������԰��Сˮ���ϣ�ͤ����Χ�Ի�������ʽ���壬����
��̸��ֲ�ͬ��ʽ��÷֦�����ʽ�������߶����컨��Ҳ�е�̷�
����ϸ�İٻ�ͼ�������µ����ʲʻ�����Ǻ�ܬʽ���Ӳ�����
���α��£�ɫ�ʷḻ��ͤ��ʯ�ŷɼܣ�ͨ����¥�����龫�ɣ�Ϊ԰
��һ���澰��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
       "north" :__DIR__"bridge1",
       "south" :__DIR__"bridge2",

]));

    set("objects", ([
        __DIR__"npc/shiren" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
