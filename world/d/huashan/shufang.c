// shufang.c
inherit ROOM;
void create()
{
        set("short", "�鷿");
        set("long", @LONG
�����ǻ�ɽ�������ˡ����ӽ�������Ⱥ���鷿��ƽʱ������
�ڴ˻�����ˡ�����ֻ�м�����ܡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"houhuayuan2",
]));
        set("objects", ([
                CLASS_D("huashan") + "/yue" : 1,
                CLASS_D("huashan") + "/ning" : 1]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
        replace_program(ROOM);
}
