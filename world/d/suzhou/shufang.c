//ROOM:/d/suzhou/shufang.c
//by dwolf
//97.11.4

inherit ROOM;

void create()
{
	set("short", "�鷿");
        set("long", 
"   ����һ�����ķ��䣬�ұ��и���������߿�ǽ��һ����ܡ�\n"
"����Ϸ���һϵ�е��飬���߽�һ�����ۣ��ǽ�ӹ������\n"
"\n"
"         �������˲���\n\n"
"��������һ�����Ӻ͵��ӣ��������������Ϣһ�¡�������(read)\n"
"������Ŀǰֻ��\n"
" 1   13  15  17  19  20  26  28  30  42  44  46  48  50 \n"
"���½ڣ���Ķ����˽�ȥ��\n"
 );
      set("exits", ([
                "west" : __DIR__"ymzting",
      ]));
	setup();
}

void init()
{
 add_action("do_read", "read");

}

int do_read(string arg)
{
 object me;
 me = this_player();
 if( !arg ) {
      me->start_more(read_file("/d/library/tian/0") );
       return 1;
 }
 if( file_size("/d/library/tian/"+arg)>0 ){
      me->start_more(read_file("/d/library/tian/"+arg) );
      return 1;
 } else {
  return notify_fail("û���Ȿ��\n");
 }

}
