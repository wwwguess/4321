inherit ROOM;

void create()
{
    set("short","СԺ");
        set("long", @LONG
��������ɽׯ���ССͥԺ������ƺ����󣬵���ľ���裬��Ŀ������
����������������������Լ���㣬����һ����ζ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"yulanc",

]));

        setup();
        replace_program(ROOM);
}
