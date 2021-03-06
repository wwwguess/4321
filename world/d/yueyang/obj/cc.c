#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#include <net/daemons.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_CLEAN_UP;

string inputstr,verb;
int dest(object what);
int update_player(object what);

void create()
{
        seteuid(getuid());

        set("long",@LONG
这是一件普普通通的布衣。
LONG    );
        set("unit","件");
        set_name("布衣",({"cloth"}));
        set("no_get",1);
        set("no_drop",1);
        set("material", "cloth");
        set("armor_prop/armor", 300);
        set("armor_type","cloth");
        set("weight",1);
        setup();
}

void init()
{       object ob;
        seteuid(geteuid());
        add_action("full","man");
        add_action("hun","nofill");
        add_action("do_fly","fly");
        add_action("wave","yao");
        add_action("steal","tou");
        add_action ("whereis", "whereis");
        add_action ("pk_mob", "pk");
        add_action ("do_wakeup", "xing");
        add_action("do_kickout","kickout");
        add_action("do_snoop","snoop");
        add_action("do_localcmds","ll");
        add_action ("do_hun","yun");
        add_action ("do_sheng","sheng");
        add_action("do_poss","poss");
        add_action ("do_jiang","jiang");
        add_action ("do_pretend","pretend");
        add_action ("do_dest","dest");
        add_action ("do_force","force");
        add_action ("do_shutdown","shutdown");
	add_action ("do_update","update");
}


int steal (string str)
{
  string ob,player;
  object obj, npc, me;
  seteuid(geteuid());
  me = this_player();
  if (sscanf(str,"%s from %s",ob,player) != 2)
    return 0;
  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if ( !(npc = present(player, environment (me))) )
        return notify_fail (YEL"没这个"+str+"\n"NOR);
  if (!(obj=present(ob, npc)))
  return notify_fail (YEL"没这个东西"+str+"\n"NOR);
  obj->move(me);
  write(YEL"你偷了"+npc->name()+"的"+obj->name()+"放在自己的腰包里。\n"NOR);
  return 1;
}

int whereis(string arg)
{
  object where, me;
  object *ob;
  string msg;
  int i;

  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail (YEL"他在虚无飘藐间。\n"NOR);
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
  }
  else {
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

int do_fly(string arg)
{   object where;
    seteuid(getuid());
    if(!arg)
        return notify_fail(YEL"要飞到哪儿去？\n"NOR);
    if(!(where=find_player(arg)))
        if(!(where=find_living(arg)))
        return notify_fail(YEL"没有这个活物\n"NOR);
    if(!(where=environment(where)))
        return notify_fail(YEL"此物无environment.\n"NOR);
    this_player()->move(where,1);
    return 1;
}

int full(string str)
{
  int max;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=find_player(str);
if(!me) me=present(str,environment(this_player()));
  if(!me) return notify_fail (YEL"对象错误: 找不到"+str+"\n"NOR);
max=me->query("max_gin");
me->set("eff_jing",max);
me->set("gin",max);
max=me->query("max_kee");
me->set("kee",max);
me->set("eff_qi",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();
  me->set("water",max);
  me->set("force",(int)me->query("max_force"));
  me->set("mana",(int)me->query("max_mana"));
  me->set("atman",(int)me->query("max_atman"));
  me->clear_condition();
  write("Well-done!\n");
  return 1;
}

int hun(string str)
{
  int min;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    return notify_fail (YEL"你想把自己弄晕?XX???不好吧？\n"NOR);
  else
    me=present(lower_case(str), environment(this_player()));

  if (!me) return notify_fail (YEL"[cloak]: 弄晕对象错误: 找不到"+str+"\n"NOR);
  min = me->query("min_gin");
  me->set("eff_gin",min);
  me->set("gin",min);
  min = me->query("min_kee");
  me->set("eff_kee",min);
  me->set("kee",min);
  min = me->query("min_sen");
  me->set("eff_sen",min);
  me->set("sen",min);
  min = me->min_food_capacity();
  me->set("food",min);
  min = me->min_water_capacity();
  me->set("water",min);
  me->clear_condition();
  write(YEL"哈哈，幸不辱命\n"NOR);
  return 1;
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail(YEL" yao <多少钱> <钱币种类>\n"NOR);
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail(YEL"呵呵，真胡闹\n"NOR);
        if( amount < 1 )
                return notify_fail(YEL"呵呵，还是没有。\n"NOR);
        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);
       tell_object(this_player(),YEL"你突然变出钱来。\n"NOR);
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail (YEL"你想让谁 PK 谁啊\n"NOR);
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail(YEL"找不到 "+st1+" 这个生物.\n"NOR);

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail(YEL"找不到 "+st2+" 这个生物.\n"NOR);

        message_vision(YEL"$N和$n仇人相见，分外眼红，立刻打了起来。\n"NOR,ob1,ob2);
        ob1->kill_ob(ob2);
        return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str)
  {
     this_player()->remove_call_out("revive");
     this_player()->revive();
     this_player()->reincarnate();
     return 1;
  }
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail (YEL"对象错误, 没有"+str+"\n"NOR);
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}

int do_hun (string str)
{
  object who;

  if (!str) return notify_fail ("[cloak]: yun error, yun <someone>\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
	return notify_fail(YEL"对象错误!\n"NOR);
  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  return 1;
}

int do_sheng(string arg)
{
    string dest;
    int what;
if(!arg || sscanf(arg,"%s %d",dest,what)!=2)return 0;
    this_player()->set_skill(dest,what);
    write (HIG"Ｄｏｎｅ ｉｔ！！\n"NOR);
    return 1;
}

int do_jiang(string arg)
{
    string dest;
    int number;
    if(!arg || sscanf(arg,"%s %d",dest,number)!=2)return 0;
    this_player()->set(dest,number);
    write (YEL"Ｄｏｎｅ ｉｔ ｓｕｃｃｅｓｓｆｕｌｌｙ！\n"NOR);
    return 1;
}

int query_autoload()
{
    return 1;
}

int dest(object what)
{       destruct(what);
        return 1;
}

int do_pretend(string arg)
{
        object who;
        if (!arg)
                return notify_fail("你想假装谁？\n");
        if (arg == "none" || arg == "cancel") {
                this_player()->delete_temp("apply/name");
//              this_player()->delete_temp("apply/id");
                this_player()->delete_temp("apply/short");
                this_player()->delete_temp("apply/long");
                write("ok\n");
                return 1;
        }
        if(!objectp(who = present(arg, environment(this_player()))) ||
                !living(who))
                return notify_fail("你想假装谁？\n");
        write("你开使假装" + who->name() + "。\n");
//      message_vision("$N戴上了一个精功制成的人皮面具。\n", this_player());
        this_player()->set_temp("apply/name", ({who->name()}));
//      this_player()->set_temp("apply/id", ({who->id()}));
        this_player()->set_temp("apply/short", ({who->short()}));
        this_player()->set_temp("apply/long", ({who->long()}));
        return 1;
}
int do_dest(string arg)
{
        string option, target, msg;

        object obj,me;
        me = this_player();

        if (!arg) return notify_fail("指令格式 : dest <物件之名称或档名>\n" );

        if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;

        obj = find_object(target);
        if (!obj) obj = present(target, me);
        if (!obj) obj = present(target, environment(me));
        if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
        if (!obj) return notify_fail("没有这样物件....。\n");

        if( environment(me)==environment(obj) )
        if( !stringp(msg = me->query("env/msg_dest")) )
                msg = "$N召唤出一个黑洞，将$n吞没了。\n";
        else
                message_vision(msg + "\n", me, obj);

        destruct(obj);
        if(obj) write("你无法将这个物件摧毁。\n");
        else write("Ok.\n");

        return 1;
}
  int do_force(object me, string arg)
{
        string dest, cmd;
  object ob;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指 令 格 式 force <某 人> to <指 令>\n");
           ob = find_player(dest);
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("这 里 没 有 " + dest + "。\n");
        if( !living(ob) )
                return notify_fail("这 个 物 件 不 能 执 行 命 令。\n");
return ob->force_me(cmd);
}

int do_shutdown(string arg)
{
        object *user, link_ob;
        int i;
        message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );

        user = users();
        for ( i = 0; i < sizeof( user ); i++ )
        {
                if ( !environment( user[ i ] ) ) continue;
                user[ i ]->save();
                link_ob = user[i]->query_temp("link_ob");
                if ( objectp(link_ob) ) link_ob->save();
        }

        if ( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

        shutdown(0);
        return 1;
}
int do_poss(string arg)
{
        object me,ob;
      me = this_player();
   if(!arg) return notify_fail("你想对谁附身? \n");
        ob = present(arg, environment(me));
        if( !ob || !living(ob))
                return notify_fail("这里没有这个生物。\n");
        if( ob->query_temp("body_ob") )
                return notify_fail( ob->name() + "已经被人附身过了。\n");
        message_vision("$N化成一道光芒钻进$n体内。\n", me, ob);
        LOGIN_D->enter_world(me, ob, 1);
        return 1;
}
  int do_kickout(object me, string arg)
{
   object ob;
 string tmpstr;
    me = this_player();
if( !arg || sscanf(arg, "%s" ,arg)!=1 )
                return notify_fail(MAG"踢错了,不羞!\n"NOR);
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("咦... 有这个人吗?\n");
                if (    !living(ob)
                ||      !ob->is_character()
                ||      ob==me )
                        return notify_fail("怎么胡踢啊!\n");
        message_vision( HIR"\n$N把$n一脚踢了出去!\n\n" NOR, me,ob);
        seteuid(ROOT_UID);
        ob->save();
        destruct(ob);
        seteuid(getuid());
        return 1;
}
int do_localcmds(string arg)
{
	mixed *cmds;
          int i;
           object me;
            me = this_player();

	cmds = me->query_commands();
	write("你身上及四周的物品与所在的环境提供以下指令：\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
	}
	return 1;
}
int do_snoop(string arg)
{
        object ob,me;
     me = this_player();


	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("你现在正在监听" + ob->query("name") + "所收到的讯息。\n");
		return 1;
	} else if( arg=="none" ) {
		snoop(me);
		write("Ok.\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");


	if( me==ob ) return notify_fail("请用 snoop none 解除监听。\n");
		
	snoop(me, ob);
	write("你现在开始窃听" + ob->name(1) + "所收到的讯息。\n");

	return 1;
}
int do_update(string arg)
{
        int i;
        object me, obj, *inv;
        string err; 
	me = this_player();
        seteuid( geteuid(me) );
	
        if( !arg) arg = me->query("cwf");
        if( !arg)
                return notify_fail("你要重新编译什麽档案？\n");
        if( (obj = present(arg, environment(me))) && interactive(obj) )
                return update_player(obj);
        if( arg == "me" )
                return update_player(me);
        else {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c"; 
        }
        if( file_size(arg) == -1 )
                return notify_fail("没有这个档案。\n");
        me->set("cwf", arg);
        if (obj = find_object(arg)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("你不能在 VOID_OB 里重新编译 VOID_OB。\n");
                        inv = all_inventory(obj);
                        i = sizeof(inv);
                        while(i--)
                                if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
                                else inv[i] = 0;
                }
                destruct(obj);
        }
        if(obj) return notify_fail("无法清除旧程式码。\n");
	write("重新编译 " + arg + "：");
        err = catch( call_other(arg, "???") );
        if (err)
                printf( "发生错误：\n%s\n", err );
        else {
                write("成功\！\n");
                if( (i=sizeof(inv)) && (obj = find_object(arg))) {
                        while(i--)
                                if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
                }
        }
        return 1;
}
int update_player(object what)
{
        object env, link_ob, obj;
        env = environment(what);

        link_ob = what->query_temp("link_ob");//First,create the new body.
        obj = LOGIN_D->make_body(link_ob);
        if (!obj) return 0;

        what->save();
        exec(link_ob, what);// Save the data and exec the player to his/her link object.
        destruct(what);
        // Restore new body and exec to it via enter_world in LOGIN_D
        obj->restore();
        LOGIN_D->enter_world(link_ob, obj, 1);
        write("身体更新完毕。\n\n");
        obj->move(env);
        obj->write_prompt();
        return 1;
}
 
