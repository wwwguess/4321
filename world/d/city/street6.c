// /d/city/street6

inherit ROOM;

void create()
{
        set("short", "��ʦ����");
        set("long", @LONG
�����������ھ�ʦ�Ľֵ��ϡ������߱����Ͻ��ǵĺ���--������
�������ƺ���һ�Ҿ�¥���������ζһ����Ʈ����������һ����԰��
��˵���澭���ֹ�����û�˸�ȥ��
LONG
        );

        set("exits", ([
                "east":         __DIR__"shenwumen",
                "south" :       __DIR__"street5",
		"west":         __DIR__"cloth",
                "north" :       __DIR__"feiyuan",
                ]));
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

