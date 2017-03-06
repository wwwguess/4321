// zhuzao.c
#include <ansi.h>
inherit NPC;
string *names = ({
         __DIR__"redgirl",
         __DIR__"orggirl",
         __DIR__"yelgirl",
         __DIR__"grngirl",
         __DIR__"cyngirl",
         __DIR__"blugirl",
         __DIR__"maggirl",
        });

string *girls= ({
          "red girl",
          "orange girl",
          "yellow girl",
          "green girl",
          "cyan girl",
          "blue girl",
          "mag girl",
         });
object girl;         
int test_array();
int tell_array();
int go_jiayi();
void create()
{
    set_name("朱藻",({"zhu zao","zhu","zao"}));
    set("long","风流倜傥\n");
    set("title","麻衣客");
    set("gender","男性");
    set("no_arrest",1);
    set("age",32);
    set("int",22);
    set("cor",30);
    set("per",30);
    set("cps",20);
    set("gin",1000);
    set("max_gin",100);
    set("eff_gin",100);
    set("max_kee",500);
    set("eff_kee",500);
    set("kee",500);  
    set("max_sen",100);
    set("sen",100);    
    set("eff_sen",100);
    set("combat_exp",500000);  
    set_skill("ill-quan",60);
    set_skill("force",90);
    set_skill("lotusforce",100);
    set_skill("cuff",100);
    set_skill("parry",150);
    set_skill("dodge",150);
    set("force",10000);
    set("max_force",10000);
    set("force_factor",200);
    map_skill("force","lotusforce");
    prepare_skill("cuff","ill-quan");
    map_skill("cuff","ill-quan");
    set("attitude", "heroism");
    set("inquiry",([
          "jiayi": (: go_jiayi :),
          "嫁衣" : (: go_jiayi :),
          "过阵": (: test_array :),
          "test": (: test_array :),
          "七仙女阵": (:tell_array :),
          ])   );
    set("chat_chance",10);     
    set("chat_msg",({
          "朱藻道：“没有人能过我的七仙女阵。”\n",
          }) );

    setup();
    carry_object(__DIR__"obj/macloth")->wear();   
    add_money("thousand-cash", 1);
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    say ("朱藻说道：“居然不远千里而来，相必是走累了，来来来，快过来坐坐。”\n");
    return 1;
}
int havenothingon(object ob)
{  
   object *inv;
   object dress;      
   int i;
   inv = all_inventory(ob);
   if (sizeof(inv)==0) return 1;
   for (i=0;i<sizeof(inv);i++){
       dress=inv[i];
       if ((string)dress->query("equipped")=="worn" ) return 0;
       }                                        
   return 1;
}
int test_array()
{
    object me;
    int i;
    me=this_player();
    
    if (query_temp("mark/arraying"))
    {
      command("say 慢来慢来，已经有人在过阵了。\n");
      return 1;
    }
    if (me->query("age")<16)
    { 
      command("sigh");
      command("say 小孩子不懂别瞎问！\n");
      return 1;
    }
    command("laugh");
    message_vision("$N说道：“好就让你见识见识！\n",this_object());
    message_vision("$N拍了拍手，从七扇门里走出七个少女，围在$n身边。\n",this_object(),me);
    set_temp("mark/arraying",1);
    for (i=6;i>=0;i--)
         {
           girl=new(names[i]);
            girl->move(environment(this_object()));
          }
   
    call_out("begin_array",2,me);
 
    return 1;
}
void begin_array(object me)
{
    message_vision("锦衣少女们轻轻一笑，身形闪动，在$N身侧围了个丈许方圆的圈子。\n",me);
    message_vision("$N拍掌道：“乐起，阵发！”\n",this_object());
    call_out("fighting",1,me,0);
    me->set_temp("mark/arraying",1);
    me->delete_temp("mark/striped");
}
void fighting(object me,int count)
{ 
    string msg; 
    object *inv;
    object dress;
    int i;
    if (havenothingon(me) && !me->query_temp("mark/striped"))
    {
       message_vision("$N哈哈笑道：“这位"+RANK_D->query_respect(me)+"倒也乖巧，就算你过阵了吧！”\n",this_object());
       me->delete_temp("mark/arraying");
       this_object()->delete_temp("mark/arraying");
       me->set_temp("mark/sucarray",1);
       message_vision("$N手一挥，七彩少女们退了下去。\n",this_object());
       for (i=0;i<7;i++)
         destruct(present(girls[i],environment()));
       return;
     }
    if (!present(me,environment(this_object())))
    { 
       message_vision("$N叹了口气，说道：“胆小如鼠的家伙，打了一半就跑了。”\n",this_object());
       me->delete_temp("mark/arraying");
       this_object()->delete_temp("mark/arraying");
       message_vision("$N手一挥，七彩少女们退了下去。\n",this_object());
       for (i=0;i<7;i++)
         destruct(present(girls[i],environment()));
       return;
    }
    i=count%7;
    girl=present(girls[i],environment());
    if (!objectp(girl)) {
               notify_fail("wrong\n");
               return;
         }
    if (i==3) 
    {
           message_vision("锦衣少女越转越快。\n",me);
           if (random(me->query("combat_exp"))<50000 && !me->is_busy())
                 {
                 message_vision("$N被转晕了\n",me);
                 me->start_busy(3);
                }

            message_vision("锦衣少女衣襟半解，长衫已褪\n",me);
            if (random(me->query_cps())<5) 
            { 
               message_vision("$N不禁想入非非起来。\n",me);
               me->unconcious();
            };
    };       
    inv = all_inventory(girl);
    dress=inv[random(sizeof(inv))];
    if( (string)dress->query("equipped")=="worn" )
        if (dress->unequip()) {
             if( !stringp(dress->query("unequip_msg")) )
                message_vision(YEL "$N将$n脱了下来。\n" NOR,girl,dress);
             else
                message_vision(dress->query("unequip_msg"),girl,dress);
        };

    if (random(100)>50){
    dress->move(environment(girl));
    destruct(dress); //we think it should to drop on ground,but..
    COMBAT_D->do_attack(girl, me, girl->query_temp("weapon"));
    }
    else{
        msg="$N气凝于臂，将手中的"+dress->name()+"向$n击去！";
        dress->move(environment(girl));
        destruct(dress);                                      
        COMBAT_D->do_attack(girl, me, girl->query_temp("weapon"),0,msg);
        }
     //query if success
   
   if(me->query("kee") <= 0   || !present(me, environment()))
   {
      command("say debug 3\n");   
      message_vision("$N叹道：“连这几招都撑不过去。”\n",this_object());
      me->delete_temp("mark/arraying");
      this_object()->delete_temp("mark/arraying");
      me->set_temp("mark/sucarray",1);
      message_vision("$N手一挥，七彩少女们退了下去。\n",this_object());
      for (i=0;i<7;i++)
         destruct(present(girls[i],environment()));
      return;  
   };               
   
   if(me->query_temp("mark/striped"))
   {          
      message_vision("$N大笑道：“怎么样，不要不自量力了”\n",this_object());
      if (!random(10)) message_vision("$N说道：“这里墙上刻的是过阵的绝招，你好好研读吧！\n",this_object());
      me->delete_temp("mark/arraying");
      this_object()->delete_temp("mark/arraying");
  
      message_vision("$N手一挥，七彩少女们退了下去。\n",this_object());
      for (i=0;i<7;i++)
         destruct(present(girls[i],environment()));
      return;  
   }                 
   
   for (i=0;i<7;i++)
       {
         girl=present(girls[i],environment());
         inv=all_inventory(girl); 
         if (sizeof(inv)) 
                {
       
                 call_out("fighting",1,me,count+1);
                 return;
                 }

       }
      message_vision("$N大笑道：“不错不错，过了这七仙女阵了。”\n",this_object());
      me->delete_temp("mark/arraying");
      me->set_temp("mark/sucarray",1);
      this_object()->delete_temp("mark/arraying");
      if (!query_temp("mark/pass_array"))
      {
      		command("say 你是今天第一个过阵的，很好很好。");
      		me->add("combat_exp",50+random(100));
      		me->add("potential",50+random(150));
      }
      set_temp("mark/pass_array",1);
      message_vision("$N手一挥，七彩少女们退了下去。\n",this_object());
      for (i=0;i<7;i++)
         destruct(present(girls[i],environment()));
      return;   
   
}        
int tell_array()
{
   message_vision("$N大笑道：“此阵只应天上有，人间那得几回闻，$n若一闯此阵，纵然输了，福气也算不错。”\n",this_object(),this_player());
   message_vision("此阵是七个绝色少女，武功虽不高，但也不弱，她们七人将你围在中央，\n一面脱衣，一面动手脱你的衣服，等她七人衣服脱尽，而你的衣服未被她\n们脱下一件，这一阵便算你赢了。\n",this_player());
   return 1;

}
int go_jiayi()
{
	object me;
	object ark;
    string myfile;
    myfile=base_name(this_object());
    //I do not want to specify an abs name of a room
    myfile=replace_string(myfile,"npc/zhuzao","ark");
	me=this_player();
	if (!me->query("marks/嫁衣"))
		message_vision("$N冷冷地瞪了$n一眼，“你问这个做什么？”\n",this_object(),me);
	else	
	{
		command("say 谢谢你帮助了我的母亲，你现在去见见她吧！");
		if (!objectp(ark=find_object(myfile)))
                ark=load_object(myfile);
        me->move(ark);
    }
    return 1;
}
