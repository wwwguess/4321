// kickout.c
#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        string tmpstr;
        if( me!=this_player(1) ) return 0;
        if( !arg || sscanf(arg, "%s", arg)!=1 )
                return notify_fail("ָ���ʽ : kickout <ĳ��>\n");
        if(!wizardp(me))
                return 0;
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("��... û�������?\n");
                if (    !living(ob)
                ||      !ob->is_character()
                ||      ob==me )
                        return notify_fail("����˰ɣ������ô�����أ�\n");
        message_vision( HIW "\n$Nһ����Ű�$n�����˳�ȥ\n\n" NOR, me,ob);
        seteuid(ROOT_UID);
        ob->save();
        destruct(ob);
        seteuid(getuid());
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : kickout <ĳ��>
HELP
    );
    return 1;
}
