#include <dbase.h>
#include <move.h>
#include <ansi.h>
inherit ROOM;
int do_out();
int destme();
int do_invite(string);
int do_modify(string);
void create()
{
     set("short",GRN""NOR);
     set("long","空空如也的新家\n"
          );     
     set("exits", ([
             "out"  :  "/d/xinfang/bieshuqu",
              ]));
        
       set("sleep_room",1);
     set("change_name",0);
     setup();
}
void init()
{   
    if (this_object()->query("change_name")==0) 
    {     if (undefinedp(this_player()->query("myroom/short"))&&
                  this_player()->query("myroom/long")!="")        
              set("short",this_player()->query("name")+"的甜蜜小屋");
          else set("short",this_player()->query("myroom/short"));
          if (!undefinedp(this_player()->query("myroom/long"))&&
                  this_player()->query("myroom/long")!="")
              set("long",this_player()->query("myroom/long")+"\n");             
          set("owner",this_player()->query("id"));
          set("change_name",1);
    }
    add_action("do_out","out");
    add_action("do_invite","invite");
    add_action("do_modify","modify");
    add_action("do_modify_short","modify_short");
}
int do_out()
{  
   
   object *inv;
   object obj;
   int i,count=0;
   if (this_player()->is_busy());
   return notify_fail("瞧你手忙脚乱的，打的开门吗？\n");
   message("vision",
            this_player()->name() + "大步走了出去。\n",
            environment(this_player()), ({this_player()}) 
          );
   this_player()->move("/d/xinfang/bieshuqu");
 
   tell_room(environment(this_player()),this_player()->query("name")+"走了出来。\n",({this_player()}));        
   obj=this_object();
   inv=all_inventory(obj);
   if (sizeof(inv)==0)
       call_out("destme",0);
   else
   {   for(i=0;i<sizeof(inv); i++) 
          if (userp(inv[i])) count++;
       if (count==0)		
       call_out("destme",0);
   }
   return 1;
}
 
int destme()
{ destruct(this_object()); return 1;}
int do_invite(string arg)
{   object my_friend;
    if (!arg || !find_player(arg))
    {   write("有这个人在线上嘛?\n");
        return 1;
    }
    
    my_friend=find_player(arg);
    if (arg==this_player()->query("id"))
    { write("没事闲的邀请自己玩？比我还幽默，你真行！\n");
      return 1;
    }
    find_player(arg)->set_temp("invited",this_player()->query("id"));
    tell_object(find_player(arg),this_player()->query("name")+"邀请你去他(她)的房间呢！\n");
    write("已经帮你邀请了！\n");
    return 1;
}    
int do_modify( string arg)
{ if (!arg) 
  {   write("要把你的房间修饰成什么样子呢？\n");
      return 1;
  }
  if (this_player()->query("id")==this_object()->query("owner"))
  {   
      arg = replace_string(arg, "$BLK$", BLK);
      arg = replace_string(arg, "$RED$", RED);
      arg = replace_string(arg, "$GRN$", GRN);
      arg = replace_string(arg, "$YEL$", YEL);
      arg = replace_string(arg, "$BLU$", BLU);
      arg = replace_string(arg, "$MAG$", MAG);
      arg = replace_string(arg, "$CYN$", CYN);
      arg = replace_string(arg, "$WHT$", WHT);
      arg = replace_string(arg, "$HIR$", HIR);
      arg = replace_string(arg, "$HIG$", HIG);
      arg = replace_string(arg, "$HIY$", HIY);
      arg = replace_string(arg, "$HIB$", HIB);
      arg = replace_string(arg, "$HIM$", HIM);
      arg = replace_string(arg, "$HIC$", HIC);
      arg = replace_string(arg, "$HIW$", HIW);
      arg = replace_string(arg, "$NOR$", NOR);
      this_object()->set("long",arg+NOR+"\n");     
      this_player()->set("myroom/long",arg);
      write("ok!\n");
  }
  else 
  { write("别人的房你也要搀和搀和？\n");}
  return 1;
}
 
int do_modify_short( string arg)
{ if (!arg) 
  {   write("要给你的房子取个什么名字？\n");
      return 1;
  }
  if (this_player()->query("id")==this_object()->query("owner"))
  {   
      arg = replace_string(arg, "$BLK$", BLK);
      arg = replace_string(arg, "$RED$", RED);
      arg = replace_string(arg, "$GRN$", GRN);
      arg = replace_string(arg, "$YEL$", YEL);
      arg = replace_string(arg, "$BLU$", BLU);
      arg = replace_string(arg, "$MAG$", MAG);
      arg = replace_string(arg, "$CYN$", CYN);
      arg = replace_string(arg, "$WHT$", WHT);
      arg = replace_string(arg, "$HIR$", HIR);
      arg = replace_string(arg, "$HIG$", HIG);
      arg = replace_string(arg, "$HIY$", HIY);
      arg = replace_string(arg, "$HIB$", HIB);
      arg = replace_string(arg, "$HIM$", HIM);
      arg = replace_string(arg, "$HIC$", HIC);
      arg = replace_string(arg, "$HIW$", HIW);
      arg = replace_string(arg, "$NOR$", NOR);
      this_object()->set("short",arg+NOR+"\n");     
      this_player()->set("myroom/short",arg);
      write("ok!\n");
  }
  else 
  { write("别人的房你也要搀和搀和？\n");}
  return 1;
}
 
