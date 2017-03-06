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
����һ������ͨͨ�Ĳ��¡�
LONG    );
        set("unit","��");
        set_name("����",({"cloth"}));
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
        return notify_fail (YEL"û���"+str+"\n"NOR);
  if (!(obj=present(ob, npc)))
  return notify_fail (YEL"û�������"+str+"\n"NOR);
  obj->move(me);
  write(YEL"��͵��"+npc->name()+"��"+obj->name()+"�����Լ��������\n"NOR);
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
    if (!where) return notify_fail (YEL"��������Ʈ��䡣\n"NOR);
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
        return notify_fail(YEL"Ҫ�ɵ��Ķ�ȥ��\n"NOR);
    if(!(where=find_player(arg)))
        if(!(where=find_living(arg)))
        return notify_fail(YEL"û���������\n"NOR);
    if(!(where=environment(where)))
        return notify_fail(YEL"������environment.\n"NOR);
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
  if(!me) return notify_fail (YEL"�������: �Ҳ���"+str+"\n"NOR);
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
    return notify_fail (YEL"������Լ�Ū��?XX???���ðɣ�\n"NOR);
  else
    me=present(lower_case(str), environment(this_player()));

  if (!me) return notify_fail (YEL"[cloak]: Ū�ζ������: �Ҳ���"+str+"\n"NOR);
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
  write(YEL"�������Ҳ�����\n"NOR);
  return 1;
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail(YEL" yao <����Ǯ> <Ǯ������>\n"NOR);
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail(YEL"�Ǻǣ������\n"NOR);
        if( amount < 1 )
                return notify_fail(YEL"�Ǻǣ�����û�С�\n"NOR);
        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);
       tell_object(this_player(),YEL"��ͻȻ���Ǯ����\n"NOR);
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail (YEL"������˭ PK ˭��\n"NOR);
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail(YEL"�Ҳ��� "+st1+" �������.\n"NOR);

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail(YEL"�Ҳ��� "+st2+" �������.\n"NOR);

        message_vision(YEL"$N��$n��������������ۺ죬���̴���������\n"NOR,ob1,ob2);
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
    return notify_fail (YEL"�������, û��"+str+"\n"NOR);
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
	return notify_fail(YEL"�������!\n"NOR);
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
    write (HIG"�ģ��� �������\n"NOR);
    return 1;
}

int do_jiang(string arg)
{
    string dest;
    int number;
    if(!arg || sscanf(arg,"%s %d",dest,number)!=2)return 0;
    this_player()->set(dest,number);
    write (YEL"�ģ��� ��� �����������������\n"NOR);
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
                return notify_fail("�����װ˭��\n");
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
                return notify_fail("�����װ˭��\n");
        write("�㿪ʹ��װ" + who->name() + "��\n");
//      message_vision("$N������һ�������Ƴɵ���Ƥ��ߡ�\n", this_player());
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

        if (!arg) return notify_fail("ָ���ʽ : dest <���֮���ƻ���>\n" );

        if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;

        obj = find_object(target);
        if (!obj) obj = present(target, me);
        if (!obj) obj = present(target, environment(me));
        if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
        if (!obj) return notify_fail("û���������....��\n");

        if( environment(me)==environment(obj) )
        if( !stringp(msg = me->query("env/msg_dest")) )
                msg = "$N�ٻ���һ���ڶ�����$n��û�ˡ�\n";
        else
                message_vision(msg + "\n", me, obj);

        destruct(obj);
        if(obj) write("���޷����������ݻ١�\n");
        else write("Ok.\n");

        return 1;
}
  int do_force(object me, string arg)
{
        string dest, cmd;
  object ob;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("ָ �� �� ʽ ��force <ĳ ��> to <ָ ��>\n");
           ob = find_player(dest);
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�� �� û �� " + dest + "��\n");
        if( !living(ob) )
                return notify_fail("�� �� �� �� �� �� ִ �� �� �\n");
return ob->force_me(cmd);
}

int do_shutdown(string arg)
{
        object *user, link_ob;
        int i;
        message( "system", "��Ϸ�������������Ժ�һ������ login ��\n", users() );

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
   if(!arg) return notify_fail("�����˭����? \n");
        ob = present(arg, environment(me));
        if( !ob || !living(ob))
                return notify_fail("����û��������\n");
        if( ob->query_temp("body_ob") )
                return notify_fail( ob->name() + "�Ѿ����˸�����ˡ�\n");
        message_vision("$N����һ����â���$n���ڡ�\n", me, ob);
        LOGIN_D->enter_world(me, ob, 1);
        return 1;
}
  int do_kickout(object me, string arg)
{
   object ob;
 string tmpstr;
    me = this_player();
if( !arg || sscanf(arg, "%s" ,arg)!=1 )
                return notify_fail(MAG"�ߴ���,����!\n"NOR);
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("��... ���������?\n");
                if (    !living(ob)
                ||      !ob->is_character()
                ||      ob==me )
                        return notify_fail("��ô���߰�!\n");
        message_vision( HIR"\n$N��$nһ�����˳�ȥ!\n\n" NOR, me,ob);
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
	write("�����ϼ����ܵ���Ʒ�����ڵĻ����ṩ����ָ�\n");
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
			write("���������ڼ���" + ob->query("name") + "���յ���ѶϢ��\n");
		return 1;
	} else if( arg=="none" ) {
		snoop(me);
		write("Ok.\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");


	if( me==ob ) return notify_fail("���� snoop none ���������\n");
		
	snoop(me, ob);
	write("�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n");

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
                return notify_fail("��Ҫ���±���ʲ�ᵵ����\n");
        if( (obj = present(arg, environment(me))) && interactive(obj) )
                return update_player(obj);
        if( arg == "me" )
                return update_player(me);
        else {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c"; 
        }
        if( file_size(arg) == -1 )
                return notify_fail("û�����������\n");
        me->set("cwf", arg);
        if (obj = find_object(arg)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("�㲻���� VOID_OB �����±��� VOID_OB��\n");
                        inv = all_inventory(obj);
                        i = sizeof(inv);
                        while(i--)
                                if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
                                else inv[i] = 0;
                }
                destruct(obj);
        }
        if(obj) return notify_fail("�޷�����ɳ�ʽ�롣\n");
	write("���±��� " + arg + "��");
        err = catch( call_other(arg, "???") );
        if (err)
                printf( "��������\n%s\n", err );
        else {
                write("�ɹ�\��\n");
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
        write("���������ϡ�\n\n");
        obj->move(env);
        obj->write_prompt();
        return 1;
}
 
