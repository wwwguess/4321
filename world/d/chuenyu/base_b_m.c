// Room: /d/chuenyu/base_b_mtn.c
inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
һ���߶��յ�ɽ������������ǰ��������һ����ɽ����С·���������ۡ�
�����ε����ָ��㲻��ĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"sunnyroad",
          "up" : __DIR__"foot_b_mtn",
]));
        set("outdoors", "chuenyu");
        
        setup();
        replace_program(ROOM);
}
                          