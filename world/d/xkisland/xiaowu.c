	//xk island.xiaowu.c
//dan
inherit ROOM;
void create()
{
        set("short", "小屋");
        set("long", @LONG
这是侠客岛用来接送上岛武林人士的.没有明显的出口。
你必须向弟子确定（queding)身份.
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
           "north":"/d/quanzhou/nanmen",
]));
        set("objects", ([
               __DIR__"npc/dizi":1,
                ]));
    
        set("no_clean_up", 0);  
         set("no_fight", 1);
	set("no_sleep", 1);
        setup();
    

} 
void init()
{
	add_action("do_queding", "queding");
}

int do_queding(object ob)
{
	
        object me, jujing,feilong;
	string name1,name2;

	me  = this_object();

	if(!( jujing = find_living("jujing")) )
	jujing = load_object("/clone/npc/jujing");
	name1 = jujing->query("winner");

	if( this_player()->query("id") == name1 )
	     {  
                 set("exits/south", __DIR__"shatan2");
        	return notify_fail("欢迎巨鲸帮帮主上侠客岛,弟子让开通道.\n");
                 }
	if(!( feilong = find_living("feilong")) )
	feilong = load_object("/clone/npc/feilong");
	name2 = feilong->query("winner");

	if( this_player()->query("id") == name2 )
	     {  
                 set("exits/south", __DIR__"shatan2");
        	return notify_fail("欢迎飞龙帮帮主上侠客岛,弟子让开通道.\n");
                 }
	return notify_fail("你不是帮主,没有资格上侠客岛!!\n");
	return 1;

}  
                                           
