inherit ROOM;


void create()
{
        set("short", "СԺ");
        set("long", @LONG
Ժ���������������ݣ�������Ļ�ľ������ҩ�ݣ���ʽ������
�����ۻ����ҡ���ʯС·���ɻ����д�����Ժ��������һ���˽�ͤ��
��ɫ��ͤ������ɫ��ͤ����ͤ������һ��ʯ������ֻʯ�ʡ�
LONG
        );
        set("exits", ([ 
                "down" :__DIR__"midao/midao16",
                "west" : __DIR__"dfbbroom",
        ]));
        set("outdoors", "heimuya");
        setup();
        replace_program(ROOM);
}

