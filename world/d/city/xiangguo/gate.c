// /d/city/xiangguo/gate

inherit ROOM;

void create()
{
        set("short", "���������");
        set("long", @LONG
������������Ĵ��Ŵ�����Ȼ����ڳ���Ҳ�ǵ�λ�Ժգ������
�����鸮������������ĸ����Եĺ���öࡣһ�ж�ʮ�ּ򵥣�ֻ��
�����ϵġ�����������������������˵ĵ�λ��
LONG
        );

        set("exits", ([
                "east":         "/d/city/street4",
                ]));
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

