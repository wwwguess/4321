// é����
inherit ROOM;

void create()
{
        set("short", "é����");
        set("long", @LONG
ǰ���Ǵ�ɽ�ȣ������Բԣ���ɽ��ľ������ɽ���ϣ�����ª�Ľ������������
���é�ݣ�é��ǰ��������ľ�ƣ�������һ����������é����Ʈɢ��������
�����ƺ�����̽�׳������������˼��ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"maoroom",
  "southdown" : __DIR__"road1",
]));

        set("item_desc", ([
                "sign": "ľ����д�ľ��ǣ�СС������\n"
        ]) );
        set("outdoors", "tieflag");
        setup();
        replace_program(ROOM);
}

