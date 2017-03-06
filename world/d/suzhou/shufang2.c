//ROOM:/d/suzhou/shufang2.c
//changed by dwolf
//97.11.4

inherit ROOM;

void create()
{
	set("short", "书房");
        set("long", 
"   这是一个宽敞的房间，右边有个窗户，左边靠墙是一溜书架。\n"
"书架上放着一系列的书，你走近一看：哇！是金庸先生的\n"
"\n"
"         《天龙八部》\n\n"
"靠窗边有一排桌子和凳子，你可以在这里休息一下。看看书(read)\n"
"不过，目前只有\n"
"12  14  16  18  2   21  27  29  41  43  45  47  49 \n"
"等章节，别的都被人借去了\n"
 );
      set("exits", ([
                "west" : __DIR__"ymhting",
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
  return notify_fail("没有这本书\n");
 }

}
