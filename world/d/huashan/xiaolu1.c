// Room : /d/huashan/xiaolu1.c
//by www 



inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ��С·�ϣ�С·һ�������£���һ�������ͱڡ�·������������Զ��У�
����������ͨ����·�ϴ��δ����������һ������һЩС�ɴ��ͱ��������
LONG
        );
        
        set("exits", ([
                   "southeast" : __DIR__"square",
                "west" : __DIR__"xiaolu2",
        ]));
        set("objects", ([
                CLASS_D("huashan") + "/gao" : 1]));

        setup();
        set("no_clean_up", 0);
        setup();


}
int valid_leave(object me, string dir)
{
        if( this_player()->query_temp("marks/˼1") ) {
                this_player()->set_temp("marks/˼1", 0);
        }
        return 1;
}
