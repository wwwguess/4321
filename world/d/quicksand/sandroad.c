inherit ROOM;

void create()
{
        set("short", "ɳ��С��");
        set("long", @LONG
����ĵ�����һ�ֻƺ�ɫ�����ɫ��ʯ����Ƕ��ϸϸ�Ļ�ɳ֮�У�
�����Լ������ĸо������������������ԭ���м�ش�������������
������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"huangyie4",
  "west" : __DIR__"saikou",
]));
        set("outdoors", "quicksand");

        setup();
        replace_program(ROOM);
}
