// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
����һ�������ʽ��������е�Ĵ����ң���ʽ�������������ࡢ��
�̡����η���һ�𣬲��Ҳ��õ�һ����Ⱦ�������ҵĳ���������ϱߣ�
LONG
        );

	set("objects", ([
                __DIR__"obj/m_gou": 6,
        ]) );

	set("exits", ([
		"south" :__DIR__"zqt1",
	]));
	setup();
}


