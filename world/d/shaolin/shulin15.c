// Room: /d/shaolin/shulin15.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
        set("short", "������");
        set("long", @LONG
����ǰ��Ȼһ�ڣ������У�ֻ������ǰ�󣬵������������
�ص������֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ����
��ɡ��������գ��������ڵ�˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�
һ�Ų���ȥ������β����������ƺ���ʧ�˷�����ûͷ��Ӭ��
�����Ҵ���
LONG
        );

        set("exits", ([
                "east" : __DIR__"guangchang1w",
        ]));

        set("no_acc_drop",1);
        set("outdoors", "shaolin");
        setup();
        replace_program(ROOM);
}


